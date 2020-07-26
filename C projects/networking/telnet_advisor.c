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

    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)  
        error("Can not create listener.");

    struct sockaddr_in my_socket;
    my_socket.sin_family = PF_INET;
    my_socket.sin_port = (in_port_t)htons(3030);
    my_socket.sin_addr.s_addr = htonl(INADDR_ANY);

    int c = bind(listener_d, (struct sockaddr *) &my_socket, sizeof(my_socket));
    if (c == -1)
        error("Can not bind port.");

    if(listen(listener_d, 10) == -1)
        error("Can not listen.");
    
    puts("Waiting for connection.");

    while(1){
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
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