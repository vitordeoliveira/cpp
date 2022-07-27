#include <iostream>
#include <string.h>


void Increment(int &value)
{

    // Back to exemple 1 and see how reference with pointer

    // Correct
    value++;
}

int main()
{
    int a = 1;
    int& ref = a;
    ref = 10;

    int b = 1;
    Increment(b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}