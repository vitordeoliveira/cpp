#include <iostream>

// IN A NUTSSHELL WE USE NAMESPACES TO AVOID NAME CONFLICTS :D


int x = 100;
namespace apple::bla
{
    int x = 10;
    namespace name
    {
        void name(){};
    } // namespace name

    void print()
    {

        std::cout << "PRINT\n";
    };
    void print_again(){};
};

namespace orange
{
    namespace name
    {
        void name(){};
    } // namespace name

    void print()
    {
        std::cout << "PRINT 2\n";
    };
    void print_again(){};
};

namespace orange
{

    void test(){};
};

int main()
{
    using apple::bla::print;
    // using namespace apple::bla;
    namespace a = apple;
    namespace b = apple::bla::name;

    std::cout << a::bla::x << std::endl;
    std::cout << ::x << std::endl;

    print();
    orange::print();
    orange::test();
}