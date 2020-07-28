/*
    Wrappers for network code.
*/
#ifndef USEFUL_NETWORK_FUNCS
#define USEFUL_NETWORK_FUNCS

#include "../useful_funcs.h"
#include <arpa/inet.h>
#include <sys/socket.h>

//recv() wrapper that reads til no more characters or til newline. (socket, buffer, length)
int read_in(int socket, char *buf, int len);

//Open a listener socket. I like redundant comments sometimes because people. That is all.
int open_listener_socket();

//Binds a socket to a port. (socket, port, reusable port?(bool1/0))
void bind_to_port(int socket, int port, int reusable);

//Send data but don't hard exit() if it fails. Instead report to stderr stream. (socket, message)
int say(int socket, char *s);

#endif /* USEFUL_NETWORK_FUNCS */