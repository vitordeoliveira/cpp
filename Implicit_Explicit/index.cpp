#include <basic.h>
#define main int main()

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
    Entity(int age) : m_Name("Unknown"), m_Age(age){};
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age){};

    const int GetAge() const{
        return m_Age;
    }

    const std::string GetName() const{
        return m_Name;
    }
};

void PrintEntity(const Entity& entity){
    // Printing
    std::cout << "Entity name = " << entity.GetName() << std::endl;
    std::cout << "Entity age = " << entity.GetAge() << std::endl;
}

main
{

    PrintEntity(29);

    Entity a("Vitor");
    Entity b(22);

    Entity c = Entity("vitor");
    Entity d = Entity(23);

    Entity e = std::string("Vitor");
    Entity f = 24;

    // Entity b = "vitor";

    return 0;
}