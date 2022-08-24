#include <iostream>

class Entity
{
public:
    int x = 0;

public:
    void Print() const { std::cout << "X: " << x << " hello\n"; }
};

class ScopedPtr
{
private:
    Entity *m_Obj;

public:
    ScopedPtr(Entity *entity) : m_Obj(entity) {}

    ~ScopedPtr()
    {
        std::cout << "DELETED\n";
        delete m_Obj;
    }

    Entity *GetObj()
    {
        return m_Obj;
    }

    Entity *operator->()
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
    std::string name;
};

int main()
{
    Entity e;
    e.x = 1;
    e.Print();

    Entity *ptr = &e;
    // Entity *ptr = new Entity();
    ptr->x = 2;
    ptr->Print();

    // ScopedPtr entity(new Entity());
    ScopedPtr entity = new Entity();

    entity->x = 3;
    entity.GetObj()->Print();
    entity->Print();

    int offset = (int)&((Vector3*)0)->name;

    std::cout << offset << "\n";
}