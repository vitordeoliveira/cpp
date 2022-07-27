#include <string>
#include <iostream>

// lvalues são valores não temporarios (variaveis e etc...) esses dados podem estar sendo usados em algum outro lugar
// rvalues são valores temporarios que só existem no codigo
// É possivel fazer o overloading da função e assim tratar os dados de forma diferente quando necessario

// Com o const na frente é possivel passar rvalues para lvalues parameters, 
// pois os dados serão convertidos pelo compilador e não sera possivel alteralos

void PrintName(const std::string &lvalue)
{
    std::cout << "lvalue: " << lvalue << std::endl;
}

void PrintName1(std::string &lvalue)
{
    std::cout << "lvalue: " << lvalue << std::endl;
}

void PrintName2(std::string &&rvalue)
{
    std::cout << "rvalue: " << rvalue << std::endl;
}

int main()
{
    std::string f = "vitor";
    std::string l = "de oliveira";

    std::string fullname = f + l;

    PrintName1(fullname);
    PrintName2(f + l);

    // Error
    // PrintName1(f + l);
    // PrintName2(fullname);
}