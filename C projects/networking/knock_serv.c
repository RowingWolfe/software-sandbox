/* 
    It's a knock knock protocol because of course it is.

    BLAB: Bind, Listen, Accept, Begin.
    */

#include <sys/socket.h> // Gotta have my sockets.
#include <arpa/inet.h> // Need an internet address, get that here.
#include "../useful_funcs.h"

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

int main(){
    printf("Ahoy, this compiled!\n");

    return 0;
}