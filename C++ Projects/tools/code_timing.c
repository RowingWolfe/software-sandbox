/*
An abstraction of the chrono functions to time code execution.
Can be useful to find out where you can speed up execution and optimize.

C++11 and up.
--------------------------
Use:
Instantiate a timer object at the begining of whatever you want to start timing.
Then just call the elapsed() member function whenever you  want to know how much time has elapsed.
Possibly printing it out or logging it, wherever you want to direct your input string.

Do note that it returns a double.

Also has a .reset() member function to set the timer to start over from 0.

Note to self: VSCode is really just not having a good time with modern C++. Might need to seek out
another editor. If only clion was free...
*/

#include <chrono>

class Timer
{
private:
    //Type aliases to make accessing the nested type easier.
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

public:
    Timer(): m_beg(clock_t::now())
    {
        //Nothing to see here. This is just called on instantiation of an object of this class and
        //Will set the clock to start.
    }

    //Sets m_beg to now.
    void reset(){
        m_beg = clock_t::now();
    }

    //Returns the time elapsed as a const double.
    double elapsed() const{
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
    
}