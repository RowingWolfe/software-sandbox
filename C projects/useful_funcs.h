#include <stdio.h>
#include <string.h> 
#include <errno.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <signal.h>

//Error handler (message)
void error(char* msg);

//Signal handler (signal, handler function pointer)
int catch_signal(int sig, void (*handler)(int));