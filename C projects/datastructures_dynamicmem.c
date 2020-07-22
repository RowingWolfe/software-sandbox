/* Yeah, I named it what it is for once. 
    Chapter seems to be about building structs into complex data structures and
    dynamically allocating and cleaning up memory in the heap.

    malloc() and free() to manage heap space.

    Use valgrind and debug symbols to find memory leaks
    gcc -g adds debug info to the executable
    valgrind -s --leak-check=full ./executable
    This will give you information about memory left in the heap on exit.
*/
//Coconut airlines? Oh boy... C planes...

//Ohoho, linked lists this is nostalgic. 
#include <stdio.h>
#include <stdlib.h> //Get acacess to malloc() and free().
#include <string.h> //To get strdup.

//These NEED to be named or the compiler will freak out trying to reference an anon struct.
typedef struct island
{
    char *name; //Strings all around.
    char *opens;
    char *closes;
    struct island *next;// A pointer to the next island. I should also have one for the previous one as well.
    //But we will go at the book's pace. I am sure they have their reasons.
    //Or am I thinking of a doubly linked list? Bahahaha yeah, I think so...
    //Also need some methods but I guess we learn this later too.
    //TODO: Complete this if the book doesn't go into it.
}island;

island* create(char *name){
    island *i = malloc(sizeof(island)); //Allocates space in the heap for the island to be stored.
    i->name = strdup(name); //Makes a defensive copy to prevent overwriting the pointer with a new one... also calls malloc so needs to be free()d
    i->opens = "08:00";
    i->closes = "19:00";
    i->next = NULL;

    return i; //Returns the island's address in mem. mmmmm I like this pattern. But now we got something we gotta free.
}

//Here goes some funcs boys and girls. Hold on to your ocarinas and bolt down your flys.
void display(island *start){
    island *i = start;

    for (; i != NULL; i = i->next) //Fancy moves with that iterator there. I'ma try to remember that.
    {
        printf("Name: %s \nOpen: %s-%s\n",i->name, i->opens, i->closes);
    }
    
}

void island_creator(){
    //Reads input in a loop and adds islands to memory.
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];

    for(; fgets(name, 80, stdin) != NULL; i = next){
        next = create(name);
        if(start == NULL)
            start = next;
        if(i != NULL)
            i -> next = next;
    }
}

void release(island *start){
    //Free up the heap space we allocated.
    //Pass the first node of the linked list then iterate through and free them from mem.
    island *i = start;
    island *next = NULL;
    for(; i != NULL; i = next){ 
        next = i -> next; //Set the next one to operate on on the following iteration.
        free(i->name); //Because the names are allocated seperately they must be freed seperately.
        free(i);// Free the island from the heap.
    }
}


int main(){
    //Making some islands. I can do that. Watch.
    island banana = {"Banana","09:00", "18:00", NULL}; //No pointer to the next one yet.
    island coconut = {"Coconut","08:00", "14:00", NULL}; 
    island beeblebrox = {"Beeblebrox","11:00", "22:00", NULL}; 
    island juicetown = {"Juicetown","09:00", "18:00", NULL}; //Wish I could afford juice that wasn't full of corn syrup...

    //Then we don't follow DRY logic for a sec and link em up.
    banana.next = &coconut;
    coconut.next = &beeblebrox;
    beeblebrox.next = &juicetown; 
    printf("Islands have been made and linked, sir. Now what?\n");
    //Add one in the middle.
    island dickweed = {"Dickweed","03:00","14:00", &beeblebrox};
    coconut.next = &dickweed;
    printf("Currently on: %s next stop: %s \n",dickweed.name, dickweed.next->name); //Thanks GCC for spoting the mistake there.
    //No dot notation for that stuff. Gotta use the old -> like in your notes, fool.
    display(&banana);


    // puts("Add islands: ");
    // island_creator();
   
    //Or crash maybe with some kinda segfault perhaps? I have to clock out for today though, 5pm. That's the rules.
    //Otherwise I will stay here all night and might not absorb anything but end up with a very full notebook.

    //Through the magic of text files and discombobulation it's the next day now.

    release(&banana);//If you truly love something you must set it free.
    //Though if memory comes back I would be worried you might need an exorcist.
    return 0;
}