//A set of useful functions like signal handlers and error handlers.

#include "useful_funcs.h"

#define _GNU_SOURCE //An attempt to shut up VSCode.
//Links signals to handlers. (Takes a signal and a handler.)
//My visual studio code is throwing a bitchfit about this but it compiles so... eh.
int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}
//Called like...
//catch_signal(SIGINT, exit_gracefully);

//Error handling func (Takes a message.)
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}
//Called like...
//error("Message");


//DEBUG
// int main(){

//     return 0;
// }