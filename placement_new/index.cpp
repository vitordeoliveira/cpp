#include <iostream>

class Base
{
private:
    int number = 0;
    int number2 = 0;
    int number3 = 0;
    int number4 = 0;
    int number5 = 0;
    int number6 = 3123;

public:
    Base() { std::cout << "Constructor\n"; };
    Base(int value)
    {
        std::cout << "Constructor\n";
        number = value;
    };
    ~Base() { std::cout << "Destructor\n"; };
    void Print()
    {
        std::cout << number << std::endl;
        std::cout << this << std::endl;
    }
};

int main()
{
    // Normal Case:
    std::cout << "Normal Case\n";
    Base *obj = new Base();
    delete obj;

    // placement new case:
    std::cout << "Placement New Case\n";
    char *memory = new char[10 * sizeof(Base)];

    std::cout << "sizeof: " << sizeof(Base) << std::endl;

    // New keyword can receive size/memory_location;

    Base *obj1 = new (&memory[0]) Base(19);
    Base *obj2 = new (obj1) Base(10);
    Base *obj3 = new (&memory[sizeof(Base)]) Base(100);
    // std::cout << "memory obj2: " << obj2 << std::endl;

    obj1->Print();
    obj2->Print();
    obj3->Print();

    // We need to clean the memory manualy

    obj1->~Base();
    obj2->~Base();
    obj3->~Base();

    delete[] memory;

    // We do that because ask for memory in the heap is very cost to OS
    // This way we ask one time for all memory we need
}