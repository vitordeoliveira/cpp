#include <iostream>

int main()
{
    int a = 1;

    int *b = &a;

    int c = 10;
    int &d = c;

    float *e = (float*)&a;

    // *e = 10.3;

    b = &c;
    *b = 11;
    c = 999;
    d = 10;

    std::cout << a << std::endl;
    std::cout << *b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << *e << std::endl;
}