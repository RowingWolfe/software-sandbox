/* 

    An attempt at understanding virtual funcs and the concepts of polymorphism in C++.
    "What I Cannot Create, I Do Not Understand” - Richard Feynman

    virtual
    override
    
*/

//I'll need some IO
#include <iostream> //NOT stdio.h, we ain't C here.
#include <string> //Also need strings, rather not use C style strings for simple shit.

//Now a base class
class Base{
    private:
    int m_arbitrary_private_number{5};

    public:
    std::string m_class_name{"Base"};

    //Now a virtual function that can be overriden by derived versions based on type
    //This adds a hidden *__vptr to a v-table which is a lookup for override functions.
    virtual std::string print_class_name() { return "I am Base \n"; }
};


//Now a derived class inheriting publicly(As is the most common form of inheritance.)
class Derived : public Base{
    private:
    int m_derived_arbitrary_private_number{3}; //Nice and long. Perhaps too verbose, even.

    public:
    std::string m_class_name{"Derived"};

    //Now an override for the virtual function
    //Note: using override for all override funcs is a best practice, though not
    //Required unless you are using a different return type.
    std::string print_class_name() override { return "I am Derived \n"; }
};

//Once more for effect!
class Derived_Again : public Base{
    private:
    int really_not_important_at_all{2};

    public:
    std::string m_class_name{"Derived_Again"};

    //Another override! (Not overload, idiot. Somewhat similar but across classes.)
    std::string print_class_name() override { return "I am Derived_Again \n"; }
};

//Tell class, takes a Base object by reference to avoid slicing.
//Slicing is when you assign a derived obj to a base obj, it will slice off derived functionality
//leaving only the base. Which would happen if passed by value here.
//In which case the output would just be from the Base class rather than the derived.
std::string tell_class(Base &obj){
    return obj.print_class_name();
}

int main(){
    //First an instance of Base
    Base base;
    //Now we instance the derived classes.
    Derived d;
    Derived_Again d_again;
    //Now we make references of type Base to our derived classes.
    Base &base_d{d};
    Base &base_d_again{d_again};

    //Print the base class' name
    std::cout << base.print_class_name(); //I am Base

    //Next the  derived class name from the base reference.
    std::cout << base_d.print_class_name(); //I am Derived
    //and finally the derived again
    std::cout << base_d_again.print_class_name();//I am Derived_Again

    //Then try to print the m_class_name from each.
    std::cout << base.m_class_name << std::endl; //Base
    std::cout << base_d.m_class_name << std::endl; //Base
    std::cout << base_d_again.m_class_name << std::endl; //Base

    //And from the actual instances of each class (Obj)
    std::cout << base.m_class_name <<std::endl; //Base
    std::cout << d.m_class_name <<std::endl; //Derived
    std::cout << d_again.m_class_name <<std::endl; //Derived_Again

    std::cout << "\n\nAnd now for the loop... \n\n";

    //Where this might come in handy, say is something like this...
    ///We have an array of Base refs to derived objects...
    Base *my_base_ref_arr[] {&d, &d_again};
    //Because Arrays have to be of ONE type. There are ways around this but... hacky-er than this from what I understand.
    //Now we can loop through the array and call the overloaded funcs.
    for(int i{0}; i < 2; i++){
        std::cout << "-------------------------------------------- \n";
        std::cout << my_base_ref_arr[i]->m_class_name << std::endl; //Base
        //Now this will call the correct overriden function depending on the type
        //And all of it can be contained in an iterable despite them being different types.
        //Which I am certain is useful in ways I have not really considered as of yet since my brain is tired.
        std::cout << my_base_ref_arr[i]->print_class_name() << std::endl;
    }

    //Or it could be useful in this situation... o_o
    std::cout << "======= tell_class() ======== \n";
    std::cout << tell_class(base_d);
    std::cout << tell_class(base_d_again);


    return 0;
}