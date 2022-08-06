#include <iostream>

int main()
{

    // void pointers means the pointer doesnt care about the type

    int a = 10;
    char b = 'a';
    void *p = &a;

    std::cout << *(int*)p << std::endl;

    p = &b;
    
    std::cout << *(char*)p << std::endl;

}