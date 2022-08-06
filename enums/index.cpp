
#include <iostream>

int main()
{

    // unscoped enum:
    // enum [identifier] [: type] {enum-list};

    // scoped enum:
    // enum [class|struct] [identifier] [: type] {enum-list};

    // Forward declaration of enumerations  (C++11):
    enum A : int;         // non-scoped enum must have type specified
    enum class B;         // scoped enum defaults to int but ...
    enum class C : short; // ... may have any integral underlying type

    enum Suit : int
    {
        Diamonds,
        Hearts,
        Clubs,
        Spades
    };

    std::cout << Diamonds << "\n";
    std::cout << Suit::Diamonds << "\n";
}