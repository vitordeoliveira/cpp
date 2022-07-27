#include <iostream>
#include <string>
// #include <string.h> 

void PrintString(std::string string){ // This will create a copy in the heap memory (LAZY)
    std::cout << string << std::endl;
}

void PrintStringCorrectWay(const std::string& string){ // const to make no possible to change the original value
    std::cout << string << std::endl;
}

int main()
{

    char *name = "Vitor"; // Puts a 0 in the end to compiler knows when end
    // same thing
    const char name2[7] = {'V', 'i', 't', 'o', 'r', 0};

    // name2[1] = 'a';
    // name is a ptr will not work
    *(&name+1) = (char*)'a';

    // std::cout << name << std::endl;
    // std::cout << &name+1 << std::endl;

    std::string name3 = "Vitor";
    bool contains = name3.find("or") != std::string::npos;

    PrintStringCorrectWay(name3);
    std::cout << name3 << std::endl;

    // std::cin.get();
}