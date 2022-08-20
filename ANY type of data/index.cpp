#include <iostream>
#include <any>


// Is kinda of useless
int main (){

    std::any data;

    data = 2;
    data = std::string("vitor");
    // std::string str = std::any_cast<std::string>(data);
    std::string& str = std::any_cast<std::string&>(data);

    std::cout << str;
}       