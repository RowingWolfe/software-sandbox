/*
    Parents and children need to communicate.
    WITH PIPES! LEAD ONES! IT'S A FREE FOR ALL!
    No but really. Pipes.
    #####
*/

#include <stdio.h>
#include <string.h> //strerror() lives in here, converts error number to a string explaining the error.
#include <errno.h> //Error numbers
#include <unistd.h>
#include <stdlib.h> //Need exit()
#include <sys/types.h> //Need pid_t

//Outputs error information to terminal and exits with -1.
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}


//Opens urls passed to it in a browser. (Inefficient.)
void open_url(char *url){
    char launch[255];
    //windows (Could use a check to see the OS if NT, *nix, etc.)
    sprintf(launch, "cmd /c start %s url");
    system(launch);
    //Linux, the king of OS.
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
    //Hipster cult garbage.
    sprintf(launch, "open '%s'", url);
    system(launch);
}

int main(int argc, char *argv[]){
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=https://cnn.com/rss/celebs.xml", NULL};
    int fd[2];
    if (pipe(fd) == -1){
        error("Cannot open pipe");
    }

    pid_t pid = fork();
    if (pid == -1){
        error("Can't fork process.");
    }
    if (!pid){
       
            //If I recall correctly this means we are the child
            dup2(fd[1], 1); //We want to connect our output through the pipe
            close(fd[0]); //And close input.

            //Then we go and run an exec to run an external process from the child.
            if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1){
                error("Can not execute 'rssgossip.py'.");
            }
        //Might I just say the fish oil pill really helped. @_@
    }
    //This is where the parent process should run.
    dup2(fd[0], 0); //Connect to the pipe for input.
    close(fd[2]); //Close that output pipe.

    char line[255];
    while(fgets(line, 255, stdin)){ //Tried using fd[0] but it flipped out.
        if(line[0] == '\t'){
            open_url(line+1);
        }
    }

    return 0;
}