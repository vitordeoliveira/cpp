#include <iostream>

struct Entity
{
    int x, y;
};

int main()
{
    Entity e = {5, 8};

    int *position = (int *)&e;

    int y = *(int*)((char*)&e + 4);
    // int y = *((char*)&e + 4);

    std::cout << position[0] << ", " << position[1] << "\n";
    std::cout << *(&y+4) << "\n";
    std::cout << y << "\n";
}
