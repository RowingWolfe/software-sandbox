/*
So I decided to sit down and learn C like a good little computer scientist.
The things in this repository are the result. There will be spaghetti and rambling in comments.
There will be anger.
But it will get done, god damn it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //Interesting you have to include that.

//Main starts here.
int main(){
    char card_name[3]; //4 Characters long? 0 counts in C too right?
    int running_count = 0; //Total count of cards known.
    int turn = 0; //Total turns to have passed. OR rounds, whatever you want to call it.
    bool running = true;
    do{
    puts("Enter the card_name: ");
    scanf("%2s", card_name); //So this is how we get our imput and format it I guess? Scanf Scan+Formatting?
    //I never had to take terminal input in C before, strangely enough.
    int val = 0;

    switch (card_name[0]){
        //Switch on card name to determine val.
        //No so much like mama luigi used to make.
        case 'K':
        case 'k':
        case 'Q':
        case 'q':
        case 'J':
        case 'j':
            val = 10;
            break;
        case 'A':
        case 'a':
            val = 11;
            break;
        case 'x':
        case 'X':
            //Break the outer loop, the user wants to e(x)it.
            running=false;
            break;
        // I could probably do this better.

        default:
            if (atoi(card_name) >= 11 || atoi(card_name) <= 1)
                printf("%c is not a valid card.\n", val);
            else 
                val = atoi(card_name);

    }

//I got my wish.
/*   //Yeah but like... why if statements? Why not a switch? 
//     if (card_name[0] == 'K'){
//         val = 10;
//         //In this case why not just OR? Same outcome yeah?
//     } else if (card_name[0] == 'Q'){
//         val = 10;
//         //I guess it's redundant to teach?
//     } else if (card_name[0] == 'J'){
//         val = 10;
//     } else if (card_name[0] == 'A'){
//         val = 11;
//     }else{
//         val = atoi(card_name);
//     }
*/     

    if (val >= 3 && val <= 6){
        //puts("Count has gone up");
        running_count++;
    }else if (val == 10){
        //puts("Count has gone down");
        running_count--;
    }

    printf("The card value is: %i\n", val);
    puts("---------------------");
    printf("The running total is: %i \n", running_count);
    }while(running);

    //Of course main has to return an int.
    return 0;

}