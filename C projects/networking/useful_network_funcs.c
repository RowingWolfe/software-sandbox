/*
    
    I will keep some wrappers for networking code here, actually.

    
    As it turns out because recv wont necessarily get all the data coming in in just one gulp you need a wrapper.
    Feckin ruff m8.
    Here's the head first wrapper because fuck me if I will ever want to write this again.

    
*/

#include "useful_network_funcs.h"


//recv() wrapper that reads til no more characters or til newline. (socket, buffer, length)
int read_in(int socket, char *buf, int len){
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);

    //Keep reading til newline or no more characters.
    while ((c > 0) && (s[c-1] != '\n')){
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }

    
    if (c<0) //error
        return c;
    else if(c == 0) //empty
        buf[0] = '\0';
    else //Finished. Terminate with \0, removing \r.
        s[c-1]='\0';

    //Send the length I guess.
    return len-slen;

}

//Open a listener socket. I like redundant comments sometimes because people. That is all.
int open_listener_socket(){
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1)
        error("Can not open socket");

    return s;
}

//Binds a socket to a port. (socket, port, reusable port?(bool1/0))
void bind_to_port(int socket, int port, int reusable){
    struct sockaddr_in mr_socket; //He's sockets of fun.
    mr_socket.sin_family = PF_INET;
    mr_socket.sin_port = (in_port_t)htons(port); //OI, DUMBASS! Cast this fucking thing to a port properly! GEEZUS MAN!
    mr_socket.sin_addr.s_addr = htonl(INADDR_ANY);
    int reuse = reusable;
    if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("Can not set socket to be reusable.");
    int c = bind(socket,(struct sockaddr *) &mr_socket, sizeof(mr_socket));
    if(c == -1)
        error("Can not bind socket to port");
    printf("Bound to port: %i \n", port);
}

//Send data but don't hard exit() if it fails. Instead report to stderr stream. (socket, message)
int say(int socket, char *s){
    int result = send(socket, s, strlen(s), 0);
    if(result == -1)
        fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
    return result;
}