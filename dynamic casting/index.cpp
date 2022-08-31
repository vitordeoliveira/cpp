#include <iostream>

class Entity
{
    virtual void Print(){};
};
class Player : public Entity
{
};
class Enemy : public Entity
{
};

int main()
{
    Player *player = new Player();
    Entity *actuallyEnemy = new Enemy();

    Entity *actuallyPlayer = new Player();

    Player *p0 = dynamic_cast<Player *>(actuallyEnemy);
    Player *p1 = dynamic_cast<Player *>(actuallyPlayer);

    if (p0)
    {
        std::cout << "p0: " << p0 << "\n";
    }

    if (p1)
    {
        std::cout << "p1: " << p1 << "\n";
    }
}