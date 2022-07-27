#include <iostream>
#include <array>

class Entity
{
public:
    const static int SIZE = 5;
    int *exemple = new int[SIZE];
    int exemple2[SIZE];
    std::array<int, SIZE> exemple3;
    // exemple3.size()

    Entity()
    {
        for (int i = 0; i < SIZE; i++)
        {
            exemple[i] = 5;
        }
    }
};

int main()
{
    Entity e;

    std::cout << e.exemple[1] << std::endl;
}