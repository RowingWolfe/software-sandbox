/* Structs, matey. 
    Seem like objects/classes without methods to me. I could be mistaken.
    It looks like there may be a way to add methods to structs, I assume this is with reference or pointer?
    More research is required, got an addon that will see the following and display it to me later when I have time.
    TODO: Research structs further, for instance how do I give 'em a method?
    TODO: Figure out why the output from reading the union gives me an insane number. FIXED. String formatting issue.
*/
//Forgot my includes, foolish man.
#include <stdio.h> //Thanks GCC, a bit hungover today.

//Use enums to keep track of possible unions values.
typedef enum{
    COUNT, POUNDS, PINTS
} unit_of_measure;

//Unions allow you to store data that may be of different types. like float, int, etc.
typedef union food_quantity
{
    short count;
    float weight;
    float volume;
} food_quantity;


//I had been hoping we has something like this in C. 
//This will certainly make life way easier for me going forward.
//Ooh, typedef allows you to alias it so no more needing to write "struct fish ..." just "fish"
typedef struct food{
    const char *food_type;
    food_quantity amount;
    unit_of_measure units;
}food; //This aliases it to "food" or I could set it to "assflaps" if I wanted. Not sure why I would but maybe I am coding drunk?

typedef struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    food food;  //This looks weird but I think it works fine.
}fish;



void catalog(fish f){
    switch (f.food.units)
    {
    case POUNDS:
        printf("%s is a %s with %i teeth. %i years old. \nLast ate %f pounds of %s.\n",
        f.name, f.species, f.teeth, f.age, f.food.amount.weight, f.food.food_type); //Assuming weight for food amount.
        break;
    case COUNT:
        printf("%s is a %s with %i teeth. %i years old. \nLast ate %i %s.\n",
        f.name, f.species, f.teeth, f.age, f.food.amount.count, f.food.food_type); //Assuming weight for food amount.
        break;
    case PINTS:
        printf("%s is a %s with %i teeth. %i years old. \nLast ate %f pints of %s.\n",
        f.name, f.species, f.teeth, f.age, f.food.amount.volume, f.food.food_type); //Assuming weight for food amount.
        break;
    
    default:
        break;
    }
}

void birthday(fish *f){ //Passing a pointer so you don't just operate on a copy. 
    f->age += 1; //A better way of writing the struct pointers.
    printf("Happy birthday %s, congrats on making it to %i! \n", (*f).name, (*f).age); //Kinda funny lookin.
}

int main(){
    //Now we make a fishy in the struct. Also can't spell.
    fish snappy = {"Snappy", "Piranha", 700, 5, {"Meat", {.weight=2.2}, POUNDS}};
    fish slappy = {"Slappy", "Flounder", 0, 2, {"Worms", {.count=4}, COUNT}};
    catalog(snappy);
    birthday(&snappy); //Passing a ref instead of making a copy.
    catalog(snappy);
    catalog(slappy);

    return 0;
}