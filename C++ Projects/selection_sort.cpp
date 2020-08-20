//A selection sort implementation:
/*
    1.  Start at index 0, search array for lowest val, swap with index 0.
    2.  Move to next index up, repeat.

    Compiled with
    g++ -g -std=c++17 ./selection_sort.cpp -o selection_sort

    Could be split into it's own function, as C++ is quirky in that if you pass an array
    in a function(unlike in C) it will allow you to operate directly on the array. (Whereas
    in C it will just decay to a pointer to the first index and kinda be a pain in the ass...) but that's
    rather redundant as in the <algorithm< header we also have std::sort which does exactly what
    We're doing here... only probably more complex and less error prone. (I have not looked at it 
    as of this writing.)

    The syntax for that is
            std::sort(std::begin(sort_me), std::end(sort_me));
*/

#include <algorithm> //Has std::swap which I think is self-explainatory in the code.
#include <iostream>
#include <iterator> //for std::size though there are other ways to get the size this is more readable.

//Takes an array and the length of the array, loops through and prints out the elements.
void print_arr(int arr[], int len){
    for(int idx{0}; idx < len; ++idx){
        //I have to do this for my own pedantry.
        if(idx < len-1){
            std::cout << arr[idx] << ',';
        }else{
            //No more trailing comma. =D
            std::cout << arr[idx];
        }
        
    }
    std::cout <<'\n';
}

int main(){
    //First we need an array to sort.
    int sort_me[10]{6,4,13,21,86,42,76,9,42,11}; //Should be 10 elements, don't want to clobber the stack.
    //Gonna save some time getting this here, it will look ugly if I do it later.
    //Could also divide sizeof(sort_me)/sizeof(sort_me[0]) to get this, but this is more readable.
    //IMPORTANT: Make sure you use the -std=c++17 or greater flag for your compiler.
    constexpr int arr_len{static_cast<int>(std::size(sort_me))}; //VSCode is throwing a shitfit, should work though.

    //Print a before:
    print_arr(sort_me, arr_len);

    //Now we loop through the array from index 0 and look for the lowest value.
    for (int starting_idx{0}; starting_idx < arr_len -1; ++starting_idx){
        //We'll need a var to hold the currently known smallest index.
        int smallest_idx{ starting_idx }; 

        //Now we search for the smallest number in the array... with a nested loop.
        //Starting after the starting_idx as we already know this number and need to compare it.
        for(int current_idx{starting_idx +1}; current_idx < arr_len; ++current_idx){
            //If the number we are currently looking at is smaller than smallest_idx we want to
            //set smallest_idx to the current number.
            if(sort_me[current_idx] < sort_me[smallest_idx])
                smallest_idx = current_idx;
        }
        //Not sure if checking the index is the same would be redundant here so we'll skip it for now.
        //We swap our starting_idx value with our smallest_idx value.
        std::swap(sort_me[starting_idx], sort_me[smallest_idx]);
    }


    //print an after.
    print_arr(sort_me, arr_len);
}