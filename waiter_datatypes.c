/* Exercise about data types. 
    Supposed to help waiters bus tables or whatever.
    Totals a bill and adds tax.

    Now let's add a header.
*/

#include <stdio.h>
#include "waiter_datatypes.h"

float total = 0.0;
short count = 0;
short tax_percent = 6;



int main(){
    float val;
    printf("Price of item: ");
    while (scanf("%f", &val) == 1){
        printf("Total so far: %.2f\n", add_with_tax(val)); //%.2f shows only 2 decimal points of the float.
        puts("Price of item: ");
    }
    printf("\nFinal total: %.2f\n", total);
    printf("\nNumber of items: %hi\n", count); //%hi formats shorts.
    return 0;
}

// Down here, cheeky. Thank you header declarations for allowing me to be sloppy.
float add_with_tax(float f){
    float tax_rate = 1 + tax_percent / 100.00;
    total = total + (f * tax_rate);
    count++;
    return total;
}