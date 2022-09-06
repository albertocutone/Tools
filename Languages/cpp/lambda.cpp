// lambda is a way to write functions of classes (see ex. below) getting rid of al the overhead 
// we do not need. Unlike other languages (Java), the c++ code is static and run directly on the stack 
// (wout using heap) which is faster.
// Since c++17, it is constexpr by default
// All types of lambda are anonymous function objects
/*
/ syntax:
/ auto x = [capture](args){body}
/ extended syntax:
/ [...] (...) mutableopt throwSpecopt ->retTypeopt {...}
/ 
/ I call x(), it is like to have operator() overload in a class
/
/ in capture, I can pass values (and references) as I am using attributes of a class.
/ Inside a lambda introducer [], programmer's can state a capture for accessing data of outer scoper
/ which is not passed as argument
/ Capture by reference:
/ [&pt=something] -> lambda capture, the something variable is not copied and it has a reference.
/ Pay attention because the reference can become dangling (something goes out of scope)
/ Capture by move:
/ [t = std::move(something)]
/ Capture only what is needed (used in the lambda body):
/ [=](){} -> by value
/ [&](){} -> by ref
/ 
/ Capturless lambdas: they are convertible to function pointers
/ int (*fp)(int) = [](int x){ return x+1; };
/ the fp pointer takes an int and returns an int
/
/ Mutable lambdas:
/ [i=0]() mutable { return ++i; }; 
/ Allows modifying the i counter, beacuse, operator() is const by default
/
/ Generic lambdas: lambdas + templates
/ Are just templates under the hood
/ auto plus = [value=1](auto x){ return x + value;};
/ The lambda's call operator is acutally a template
/ auto x -> replace template<typename T> .. (T x){ ... }
/
/ This can be extended to
/ Variadic lambdas
/ auto plus = [value=1](auto... as) { return sum(as...,value); };
/
/ Advantages in using lambda:
/ 1. The code is more readable
/ 2. Improves locality of the code
/ 3. Allows to store states easily: we can capture a local variable and use it across all invocation of the lambda
/ 4. Allows several overheads in the same place: All types of lambda are anonymous function objects. Here we can work with unrelated types. 
/                                                There’s no need for a common base class.
/ 5. Improves with C++ releases
*/


#include <iostream>
#include <cstdio>

using namespace std;


class Plus {
    int value;
  public:
    Plus(int v): value(v){}

    int operator() (int x) const {
        return x + value;
    }
};

int main(){
    
    auto plus = [value=1](int x){ return x + value;};

    return 0;
}
