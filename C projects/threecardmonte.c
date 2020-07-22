/* 
    This book is fascinated with gambling, specifically card based gambling.
    No matter to me, I can use this stuff later in games. HaHAH, to be a polyglot.
*/

#include <stdio.h>

int main(){
    //char *cards = "JQK"; //This is a string literal. These are static.
    char cards[] = "JQK";
    char a_card = cards[2]; //We select the third value in the string.
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card; //Ain't we cheeky.
    puts(cards);

    return 0;
}