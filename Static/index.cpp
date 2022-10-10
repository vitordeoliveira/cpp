#include <iostream>


// this is how U declare the variable is external
extern int s_variable;


int main(){
    std::cout << s_variable << "\n";
}