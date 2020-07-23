/*
    System calls, time.h
    Shockingly system calls can be dangerous. (Sarcasm)
    That's why we use exec()
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Return an ascii string of the current local time. (Via system)
char* now()
{
    time_t t; //Create a variable to hold time
    time (&t); // Returns the current time and stores it in the location of t.
    return asctime(localtime (&t)); //Return a ascii formatted string of the time.
}

int main(){
    char comment[80];
    char cmd[120];

    fgets(comment, 80, stdin); //Remembered how to do that at least.
    //sprintf to output a string.
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    //puts(now());

    //Pass the formatted cmd to system.
    system(cmd);
    return 0;
}