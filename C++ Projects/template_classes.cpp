/* 
    An example of template classes

*/

#include <cassert>
#include <iostream>

//Declare this as a template.
//Can also have :
// template <class T, int len> to have a class get created for each size of array.
// passing len in to m_length.
template <class T>
class Array{
    private:
    int m_length{};
    //Arrays are pointers with some pointer math to determine indexes. Also a length (above)
    T *m_data{};

    public:
    //Constructor
    Array(int len){
        assert(len > 0 && "Length must be greater than 0"); //Basic error handling
        m_data = new T[len]{}; //Constructs and initialized all elements to 0
        m_length = len;
    }

    //Disable the default constructors for const Array& and the assignment operator for the same.
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
    
    //Deconstructor
    ~Array(){
        //Clean up the pointers for the data.
        delete[] m_data;
    }

    //A function to clear the m_data and set the m_length to 0.
    void Erase(){
        delete[] m_data;
        //Set the pointer of m_data to 0 so we can't mess with deallocated memory.
        m_data = nullptr;
        m_length = 0;
    }

    //Overload the subscript operator : [] to work as you would expect in an array for all types.(T)
    T& operator[](int index){
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    //Tget_length forward declaration to demonstrate templated member funcs defined outside class below.
    int get_length() const;
}; //Don't forget the ; for classes!


//The class name is Array<T>, not Array.
template <class T>
int Array<T>::get_length() const{
    return m_length;
}

int main(){

    //Construct an array of 12 ints.
    Array<int> int_arr(12);
    //Construct an array of 13 char16_t.
    Array<char16_t> char_arr(13);

    //Assign incrementally to the int_arr.
    for (int count{0}; count < int_arr.get_length(); ++count)
        int_arr[count] = count;

    //Print the int_arr with each element on a new line.
    for (int count{0}; count < int_arr.get_length(); ++count)
        std::cout << int_arr[count] << std::endl;

    return 0;
}