/* Fair enough, could be practical for other things later. Working with strings
*/

#include <stdio.h>
#include <string.h>

char tracks[][80] = {
    "Doot de doot",
    "Boop de snoot",
    "Shabamzos"
};

void find_track(char seach_for[]){
    int i;
    //Loop through tracks
    for (i=0; i < 5; i++){
        //Search string
        if(strstr(tracks[i], seach_for)){
            //Return track.
            printf("Track %i: %s", i, tracks[i]);
        }else{
            puts("Could not find matching track.");
        }
    }
}

int main()
{
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    search_for[strlen(search_for) - 1] = '\0';
    find_track(search_for);
    return 0;
}