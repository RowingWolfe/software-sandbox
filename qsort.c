/*
 Ooh, did not know we had built in quicksort. I wrote this in JS and Python some time ago. 
 Oof this got messy fast. But I got there in the end.
Well, yeah. It works I guess. Probably not great though lol spent too much time fussing with ways to get
my array sizes in a more dynamic manner but pointers still hurt me noggin.
 */

#include <stdlib.h> //I guess qsort comes as part of the stdlib?
#include <stdio.h>


//Need a comparator function. Returns a-b.
int compare_ints_asc(const void *int_a, const void *int_b){
    //Gotta cast args to their original type.
    int num_a = *(int*)int_a;
    int num_b = *(int*)int_b;
    //Then return a-b which will give an ascending order.
    return  num_a - num_b; 
}

int compare_ints_dsc(const void *int_a, const void *int_b){
    //Gotta cast args to their original type.
    int num_a = *(int*)int_a;
    int num_b = *(int*)int_b;
    //Then return a-b which will give an ascending order.
    return  num_b - num_a; 
}


//Takes an array of ints and prints them
/* array will decay to a pointer, so the length must be passed separately */
void print_array_of_ints(int *arr, int arr_length){
    //int arr_length = sizeof(arr)/sizeof(int);
    //printf("Array length in print function: %i \n", arr_length);
    for (int i = 0; i < 10; i++){
        printf("%i ",arr[i]);
    }
    printf("\n");
}




int main(){
    //Let's operate on an array of ints.
    int some_ints[] = {1,65,343,86, 22, 1098, 23,64,35,11};
    //We gotta know how long it is and this is one way of getting that dynamically.
    int some_ints_size = (int)sizeof(some_ints)/sizeof(int);

    printf("Array before: ");
    print_array_of_ints(some_ints, some_ints_size);
    qsort(some_ints, some_ints_size, sizeof(int), compare_ints_asc);

    printf("Array after: ");
    print_array_of_ints(some_ints, some_ints_size);
    qsort(some_ints, some_ints_size, sizeof(int), compare_ints_dsc);
    printf("Array reversed: ");
    print_array_of_ints(some_ints, some_ints_size);
  
    return 0;
}