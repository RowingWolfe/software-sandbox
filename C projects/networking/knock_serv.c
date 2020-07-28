/* 
    It's a knock knock protocol because of course it is.

    BLAB: Bind, Listen, Accept, Begin.
    Alright, seem to have got it working. 
    There was an issue in useful_network_funcs in the port binding.
    I forgot to cast it to a value that would fit a port and so it was like 50432 or some crazy crap.

    Found the error by checking currently active ports while the server was running then scanning through
    all the code where I dealt with binding it. Noticed I just had it set to port instead of
    (in_port_t)htons(port)
    */

#include "useful_network_funcs.h"

/*
    Creating a socket.
    -------------------
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)
        error("Can't open socket");
*/

/*
    Binding a port
    -------------------
    int my_port = 30000
    struct sockaddr_in my_socket;
    my_socket.sin_family = PF_INET;
    my_socket.sin_port = (in_port_t)htons(my_port);
    my_socket.sin_addr.s_addr = hton1(INADDR_ANY);
    int c = bind(listener_d, (struct sockaddr *) &my_socket, sizeof(my_socket));
    if (c == -1){
        printf("Unable to bind to port %i \n", my_port);
        error("Can't bind to port.");
    }
*/

/*
    Listening
    -------------
    if(listen(listener_d, 10) == -1)
        error("Can't listen. Deaf port over here.");
*/

/*
    Accepting
    ------------
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
    if(connect_d == -1)
        error("Can't open secondary socket.");
*/

/*
    Sending
    -----------
    char *msg = "Some text to send from the server";
    if(send(connect_d, msg, strlen(msg), 0) == -1)
        error("Could not send.");
*/

int listener_d; //Gotta holt the main listener socket somewhere.

//If we receive a SIGTERM we exit gracefully and close the socket.
void handle_shutdown(int sig){
    if(listener_d)
        close(listener_d);
    
    fprintf(stderr, "Closing main socket and exiting now, goodbye. \n");
    exit(0);
}

int main(){
    printf("Behold, the knock sock!\n");
    if(catch_signal(SIGINT, handle_shutdown) ==-1)
        error("Can not setup signal handler for SIGINT");
    //Create a socket.
    listener_d = open_listener_socket();
    //Bind the knocksock to port 3030 and makes the port reusable.
    bind_to_port(listener_d,3033,1);

    //Listen
    if(listen(listener_d, 10) == -1)
        error("Can't listen. Deaf port over here.");
    else
        puts("Listening for connections.");

    char buf[255]; //Buffer for incoming messages.

    
    //Accept and handle.
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    while(1){
        puts("... waiting");
        int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
        if (connect_d == -1)
            error("Can not create secondary socket.");
        puts("Connection received.");
        
        //Fork to handle multiple connections. If it returns 0 we're in the child proc.
        if(!fork()){
            close(listener_d); //Child doesn't need to listen for new connections.
            //Banter
            if(say(connect_d,"Ahoy, fuckface and welcome to the knock sock!\n") == -1)
                puts("Unable to send message.");
            if(say(connect_d,"What do you have to say for yourself? \n") == -1)
                puts("Unable to send message.");
            if(say(connect_d,"Respond: ") == -1)
                puts("Unable to send message.");
            
            //Read buffer from client.
            read_in(connect_d, buf, sizeof(buf));
            puts("Response from client:");
            puts(buf);

            if(say(connect_d, buf) == -1)
                puts("Can not send buffer back to client.");
            
            //Child process cleanup.
            close(connect_d); //Close socket.
            exit(0);
        }



        //Parent only needs listen_d, child does the talking.
        close(connect_d);
    }

    return 0;
}