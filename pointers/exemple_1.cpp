#include <iostream>
#include <string.h>

// COPY
// void Increment(int value){
//     value++;
// }

// Pointer
void Increment(int *value)
{

    // This dont work will try to increment the poiter it self
    // The order is backwards first add then reference, so U need to say the order of operations to compiler
    // *value++;

    // Correct
    (*value)++;
}

int main()
{
    char *buffer = new char[8];
    *buffer = 10;
    memset(buffer, 1, 8);
    // int test = 10;
    std::cout << sizeof(buffer) << std::endl;
    std::cout << &buffer << std::endl;

    int a = 10;
    Increment(&a);
    std::cout << a << std::endl;
}