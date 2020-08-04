//Herein lies some fiddling with iostream. Hello world, if you will.

#include <iostream> //I wonder how different this is from C io these days.
#include <string>

//Not gonna bother with namespaces here. Simple stuff and it's important to remember 
// what namespace this stuff is in. I'll just explicitly declare I am using the std:: namespace.

int main(){
    std::cout << "Hello, " << "World. \n"; // \n is a newline character, like in C.
    std::cout << "How about that weather? :";
    //char *response{}; //Direct bracket initialization. Better to initialize than have undefined behavior.
    std::string response{}; //Interesting.
    //Standard cin will terminate with whitespace.
    //std::cin >> response;

    //So we use getline.
    std::getline(std::cin, response);
    //Can use std::endl for a new line and to flush output. 
    //Don't really usually need it though, can use  '\n' like in C.
    std::cout << "Why yes, I suppose it is " << response << "." << std::endl; //How do we do string formatting?

    int x{5}; //5 is a literal constant, x however can be reassigned to.
    std::cout << x << '\n';
    x = 22; //but if you want to make 5 == 6 somehow, good luck with that, matey.
    std::cout << x << '\n';
    return 0;
}