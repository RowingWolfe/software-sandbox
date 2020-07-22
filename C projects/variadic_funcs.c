/*
    The stretchy functions, variable param numbers.
    Eyes burn for some reason but we're off.
*/

#include <stdio.h>
#include <stdarg.h>

// Enumerated drinks. Let's get shitfaced.
enum drink {MUDSLIDE, FUZZY_NAVEL,MONKEY_GLAND, ZOMBIE, OLD_FASHIONED, WHISKEY};

//Switch on enum (drink) return double with price.
double price (enum drink d)
{
    switch (d){
        case MUDSLIDE:
            return 6.79;
            break;
        case FUZZY_NAVEL:
            return 5.31;
            break;
        case MONKEY_GLAND:
            return 4.82;
            break;
        case ZOMBIE:
            return 5.89;
            break;
        case OLD_FASHIONED:
            return 2.50;
            break;
        case WHISKEY:
            return 1.24;
            break;
        default:
            return 0;
            break; //Redundant? Probably.
    }
}

//Get the total for all drinks. Expect int because enum.
double total(int args, ...){
    double total = 0.0;
    
    //Some macros provided by stdarg header
    va_list ap; //Creates a list from the args.
    va_start(ap, args); //Where to start parsing from.

    //Now we loop through the args and call price, then add it to the total.
    for(int i = 0; i < args; i++){
        //Call price() on current arg and add it to the total.
        //printf("Price added: %.2f \n", price(va_arg(ap, enum drink))); //DEBUG -- Formatting issue in print found.
        //total += price(va_arg(ap, enum drink)); //Expect this to return the price of the drink and add it to the total.
        //printf("Running total: %.2f \n", total); //DEBUG -- Yeah, I got no idea.

        //I guess we have to turn it into the enum seperately from calling price on it? Why? Where did I fuck up?
        enum drink d = va_arg(ap, enum drink); //I am missing how this is different from my way in essence.
        total += price(d); //I guess trying to do that in one line was my downfall?
    }
    //End the variadic function macro.
    va_end(ap);
    // And return the total.
    return total;
}


int main(){
    printf("Total: %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL)); //16.9 expected.
    printf("Price of Fuzzy navel: %.2f\n", price(FUZZY_NAVEL));
    printf("Total: %.2f\n", total(5, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL, WHISKEY, OLD_FASHIONED));

    return 0;
}