#include <iostream>
#include <string>

class Printable
{

public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    virtual std::string Getname() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string &name) : m_Name(name){};
    std::string Getname() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->Getname() << std::endl;
}

void Print(Printable *obj)
{
    std::cout << obj->GetClassName() << "\n";
}

int main()
{
    Entity *e = new Entity();
    // PrintName(e);

    // Entity e;
    // PrintName(&e);

    // Player *p = new Player("vitor");
    // PrintName(p);

    Player p("Vitor");
    // PrintName(&p);

    Print(e);
    Print(&p);
}