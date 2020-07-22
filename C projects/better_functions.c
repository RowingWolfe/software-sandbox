/*
    With such hits as passing a function to a function and other stuff to make sure you DRY.

    As it stands this is broken as shit right now. I have not the focus to fix it.
    
    Welp, it doesn't compile and I'm not sure I understand the underlying concepts properly.
    I will have to read through this chapter completely and maybe I will figure it out? Or maybe it just can't.

    Or not, I think I got it. Sweet. I was just getting ready to go to reddit or stack overflow.

*/

#include <stdio.h>
#include <string.h>

const int NUM_ADS = 2;
//Forgot the syntax for an array of char arrays too. Oof...
char *ads[]={"Dog","Banana","Sausage"};
//To pass a func to a func as a param you gotta do some setup.
//First I need a function... 

// Checks if a string is inside another string. Takes another function that takes a char*.
void find(int(*match)(char*)){
    int i;
    for (i=0; i<NUM_ADS; i++){
        if(match(ads[i])){
            printf("Found: %s \n",ads[i]);
        }
    }
}

//Make a func to pass to the find() function that searches for "Banana".
int find_banana_not_apple(char* s){
    return strstr(s, "Banana") && !strstr(s, "Apple"); 
}

//Make a pointer version of the function...
int (*find_banana_fn)(char*) = find_banana_not_apple;




int main(){
    find(find_banana_fn); //Pass the find_banana function to the find function.

    return 0;
}

//Yeah I gotta walk away before I fuck myself up.
//Next day now, ate something that maybe might not go well in my system. See if I can fix this.