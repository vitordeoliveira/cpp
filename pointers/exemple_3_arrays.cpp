#include <iostream>

int main()
{
    // STACK MEMORY
    int exemple[5];
    int *ptr = exemple;

    exemple[2] = 5;
    std::cout << exemple[2] << std::endl;
    *(ptr + 2) = 10;
    std::cout << *(ptr + 2) << std::endl;

    *((char *)ptr + 8) = 100;

    // *(int*)((char *)ptr + 8) = 11;
    std::cout << *(ptr + 2) << std::endl;

    exemple[3] = 5;
    std::cout << exemple[3] << std::endl;

    int size_of_exemple = sizeof(exemple) / sizeof(int);
    std::cout << sizeof(exemple) << std::endl;
    std::cout << size_of_exemple << std::endl;

    // HEAP MEMORY
    int *another = new int[5];
    delete[] another;
}