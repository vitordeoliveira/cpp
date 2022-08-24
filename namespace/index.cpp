#include <iostream>

// IN A NUTSSHELL WE USE NAMESPACES TO AVOID NAME CONFLICTS :D

namespace apple::bla
{
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
    namespace a = apple;
    namespace b = apple::bla::name;

    orange::print();
    orange::test();
}