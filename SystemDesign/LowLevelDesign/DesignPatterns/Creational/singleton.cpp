// Singleton is a creational design pattern that lets you ensure that a class has only one instance,
// while providing a global access point to this instance.

// 1. Make the default constructor private
// 2. Create a static creation method that acts as a constructor (or call the existing object).
//    The Singleton class declares the static method getInstance that returns the same instance of its own class.

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

class Singleton {
  protected:
    Singleton(const std::string value): value_(value){}
    static Singleton *singleton_;
    std::string value_;
  public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const std::string& value);

    void SomeLogic(){}

    std::string value() const {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton *Singleton::GetInstance( const std::string& value){
    if(singleton_==nullptr){
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
