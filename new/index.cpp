#include <iostream>

class Entity
{
public:
    /* data */
    Entity()
    {
        std::cout << "aaa\n";
    }
};

int main()
{
    int *a = new int;
    // This one calls the constructor
    Entity *b = new Entity;

    // This one did not calls the constructor
    // Entity *b = (Entity *)malloc(sizeof(Entity));

    delete b;
    // free(b) with the destructor;
}