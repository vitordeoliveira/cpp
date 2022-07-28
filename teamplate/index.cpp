#include <basic.h>

// The code is genereted in compiled time
template<typename T, size_t s>
void Print(T value){
    std::cout << value << std::endl;
    std::cout << s << std::endl;
}

int main(){

    Print<int,2>(123);
    // Print("vitor");

}