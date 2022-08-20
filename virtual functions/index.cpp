#include <iostream>
#include <string>

// Te two imposratn things here is the virtual and override keywords

class Entity
{
public:
    virtual std::string Getname() { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name){};
    std::string Getname() override { return m_Name; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->Getname() << std::endl;
}

int main()
{
    // Entity *e = new Entity();
    // PrintName(e);

    Entity e;
    PrintName(&e);

    // Player *p = new Player("vitor");
    // PrintName(p);

    Player p("Vitor");
    PrintName(&p);
}