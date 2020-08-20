/*
Bubble sort 
    Compare arr element 0 with element 1, swap the 0 right if larger than 1.
    Move up to the next element and repeat til the end of the arr.
    Do this for each element.

While I am certain there are far better implementations, I am trying to get through a lot
in a short time and due to these time constraints some thoughts I had about optimization will be
omitted. It's been a long time since I wrote a bubble sort though, so I am happy it works at all =D

In order to get std::size you need to compile with the -std=c++17 flag like so:
g++ -std=c++17 ./bubble_sort.cpp -o bubble_sort
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
    //First an array.
    int sort_me[]{10,96,31,13,42,21};
    //and it's length.
    constexpr int arr_len{static_cast<int>(std::size(sort_me))};
    //Print a before:
    print_arr(sort_me, arr_len);

    //Then a loop to iterate through it's elements.
    for(int idx{0}; idx < arr_len -1; idx++){
        //Do this once for each element in the arr.
        for(int cur_idx{0}; cur_idx < arr_len-1; ++cur_idx){
            //Compare cur_idx with cur_idx+1
            if (sort_me[cur_idx] > sort_me[cur_idx+1]){
                std::swap(sort_me[cur_idx], sort_me[cur_idx+1]);
            }
        }
    }

    print_arr(sort_me, arr_len);


}