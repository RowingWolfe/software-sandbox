/* 
    An exercise in enumerating function pointers.
    It's a doozy, that one-liner. I guess I prefer my code to be more readable.
*/

#include <stdio.h>
#include <stdlib.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct 
{
    char *name;
    enum response_type type;
} response;

void dump(response r){
    puts(r.name);
    puts("Dumped");
}

void second_chance(response r){
    puts(r.name);
    puts("Second Chance");
}

void marriage(response r){
    puts(r.name);
    puts("Married");
}

//Creates an array of function pointers from replies, has to be the same order as the ENUM(response type).
void (*replies[])(response) = {dump, second_chance, marriage};

int main(){
    //An array of structs with a name and enum.
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Blast Hardcheese", MARRIAGE}
    };
    //For each item in r...
    for(int i =0; i<3; i++){
        // Look through array of function names for to match response[i]'s type to a function pointer.
        (replies[r[i].type])(r[i]); //Then call the function via the pointer with (r[i]) 
        //and pass it the struct contained in r[i].
        //Feels almost like I wrote more comments instead of more code to explain the one-liner but meh.
        /*
        THE BREAKDOWN
        ==============================
            replies = the array of function pointers to look in.
            [r[i].type] returns an enum so dump == DUMP == 0.
            (r[i]) then passes the response {"Mike", DUMP} to the found
            Alltogether it will locate the function pointer via the enum and call it, passing it r[i].
        */

    }

    return 0;
}