#include <iostream>

class Entity
{
private:
    int x;
    int *y;

    // mutable allow const methods to modify the value
    mutable int var;

public:
    int GetX() const
    {
        // U cant modify any member
        // x = 10;
        var = 10;
        return x;
    }
};

int main()
{

    int x = 8;

    auto f = [x]() mutable
    {
        std::cout << "f1 " << ++x << "\n";
    };

    auto f2 = [&x]()
    {
        std::cout << "f2 " << ++x << "\n";
    };

    auto f3 = [=]() mutable
    {
        std::cout << "f3 " << ++x << "\n";
    };

    f2();
    f2();
    f();
    f3();
    std::cout << x << "\n";
}