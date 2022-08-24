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

    // Pointer and the contect cant be mobified and the function will not change any member
    const int *const GetY() const
    {
        return y;
    }

    void SetX()
    {
        x = 10;
    }
};

void Print(const Entity &e)
{
    std::cout << e.GetX() << "\n";
}

int main()
{
    const int MAX = 90;

    // U cant modify the pointer
    int *const a = new int;
    int *b = new int;

    // U cant modify the content
    // const int *c = new int; (same thing)
    int const *c = new int;

    // U cant modify the pointer
    // U cant modify the content
    const int *const d = new int;

    *a = 2;
    // I cant do that
    // a = &MAX;

    *b = 2;
    // Diferent types (kinda) but U can cast (not recomend)
    // b =&MAX;
    b = (int *)&MAX;

    c = &MAX;
    // I cant do that
    // *c = 2;

    // *d = 2;

    std::cout << *a << "\n";
    std::cout << *b << "\n";
    std::cout << *c << "\n";
    std::cout << *d << "\n";
}