/*
    Handling shit hitting the fan with system calls.
    Also exec funcs.
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main (){

    if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) ==-1)
        if(execlp("ipconfig", "ipconfig", NULL) ==-1){
            fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
            return 1;
        }

    return 0;
}