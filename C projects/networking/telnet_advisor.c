/* Magic 8 ball through telnet. Ah the bbs times. */

#include "../useful_funcs.h"
#include <arpa/inet.h>
#include <sys/socket.h>

//Error handling func (Takes a message.)
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}

int main(int argc, char *argv[]){
    //TODO: Write some nonsense.
    char *advice[] = {"One","Two","Three"};

    //Create a listener 
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)  
        error("Can not create listener.");

    //Construct a socket on port 3030
    struct sockaddr_in my_socket;
    my_socket.sin_family = PF_INET;
    my_socket.sin_port = (in_port_t)htons(3031);
    my_socket.sin_addr.s_addr = htonl(INADDR_ANY);

    //Allow for the port to be reused so I don't have to wait for the timeout to restart this bastard.
    //Not sure why the int exactly.
    int reuse = 1;
    if(setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1)
        error("Can not set socket option for reuse.");

    //Bind the socket to the port.
    int c = bind(listener_d, (struct sockaddr *) &my_socket, sizeof(my_socket));
    if (c == -1)
        error("Can not bind port.");

    //Create a listener queue.
    if(listen(listener_d, 10) == -1)
        error("Can not listen.");
    
    puts("Waiting for connection.");

    //Listen and respond.
    while(1){
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    // Accept a connection, store a secondary socket for the connection.
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
    if (connect_d == -1)
        error("Can not create secondary socket.");

    char *msg = "Yo, dickhead \n"; //advice[rand() % 3];

    if(send(connect_d, msg, strlen(msg), 0) == -1)
        error("Could not send message.");
    
    puts("Responded");
    close(connect_d);
    }

    return 0;
}