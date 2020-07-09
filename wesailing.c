/* 
    So right, the book wants me to make a game where you navigate the BERMUDA RECTANGLE to safety.
    This is a lesson on pointers and why I need them so hopefully I comment this code properly. 
    See also; beat up stained ass notebook.
*/




//Here we go
#include <stdio.h>

//No namespaces here, we are real computer scientists! WE BE CODEBLOXIN.

//Same concept can be used in graphical games, just setting the x,y of a sprite really.
void go_south_east(int lat, int lon){ // No long for you. It's a keyword. HA!
    lat = lat-1;
    lon = lon+1; //THESE ARE JUST COPIES! WHAT DID I DO TO DESERVE THIS, BOOK!?
    //WHERE IS SHE!? (I like that I can hide my stupid jokes with by making them collapse.)
    /*
          .  .
          |\_|\
          | a_a\
          | | "]
      ____| '-\___
     /.----.___.-'\
    //        _    \
   //   .-. (~v~) /|
  |'|  /\:  .--  / \
 // |-/  \_/____/\/~|
|/  \ |  []_|_|_] \ |
| \  | \ |___   _\ ]_}
| |  '-' /   '.'  |
| |     /    /|:  | 
| |     |   / |:  /\
| |     /  /  |  /  \
| |    |  /  /  |    \
\ |    |/\/  |/|/\    \
 \|\ |\|  |  | / /\/\__\
  \ \| | /   | |__
snd    / |   |____)
       |_/
    */
}

//The load bearing code.
int main(){
    int latitude = 32;
    int longitude = -64; //I got a bad feeling about this one.
    go_south_east(latitude,longitude);
    printf("Ahoy, ye scurvy bastard. We now be at [%i, %i]", latitude, longitude);

    return 0;
}