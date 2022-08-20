#include <iostream>

class Entity
{

private:
    float X = 0, Y = 0;

public:
    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

    void PrintPosition()
    {
        std::cout << "X: " << X << "\nY: " << Y << "\n";
    }
};

class Player : private Entity
{
public:
    const char *Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }

    void Bla(int a, int b)
    {
        Entity::Move(a, b);
        Entity::PrintPosition();
    }
};

int main()
{

    Player player;
    Player player2;

    player.Name = "vitor";

    // player.Move(1, 2);
    // player.Move(3, 2);
    player.Bla(1, 4);

    player.PrintName();
    player2.Bla(0, 0);
    // player.PrintPosition();
}