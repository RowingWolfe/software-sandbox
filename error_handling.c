/*
    Handling shit hitting the fan with system calls.
    Also exec funcs.
*/

#include <stdio.h>
#include <string.h> //strerror() lives in here, converts error number to a string explaining the error.
#include <errno.h> //Error numbers
#include <unistd.h>
#include <stdlib.h> //Need exit()

//There has to be a better way...
//Oh wait.
//Error handler.
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}

int main (){
    //If this fails (==-1) Otherwise run it.
    if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) ==-1)
        //Likewise to above.
        if(execlp("ipconfig", "ipconfig", NULL) ==-1){

            //Too much code.
            //Print "Cannot run ipconfig and a string representation of the error."
            //fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
            //Return -1 because shit went badly.
            //return -1;

            error("Cannot run ipconfig");
        }

    return 0;
}