/*
So I decided to sit down and learn C like a good little computer scientist.
The things in this repository are the result. There will be spaghetti and rambling in comments.
There will be anger.
But it will get done, god damn it.
*/
#include <stdio.h>
#include <stdlib.h>

//Main starts here.
int main(){
    char card_name[3]; //4 Characters long? 0 counts in C too right?
    puts("Enter the card_name: ");
    scanf("%2s", card_name); //So this is how we get our imput and format it I guess? Scanf Scan+Formatting?
    //I never had to take terminal input in C before, strangely enough.
    int val = 0;

    switch (card_name[0]){
        //Switch on card name to determine val.
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
        default:
            val = atoi(card_name);
    }

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
        puts("Count has gone up");
    }else if (val == 10){
        puts("Count has gone down");
    }

    printf("The card value is: %i\n", val);

    //Of course main has to return an int.
    return 0;

}