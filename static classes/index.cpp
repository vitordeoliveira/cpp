#include <iostream>

struct Entity
{
    int x, y;

    // Inline to define the static variable default value
    static inline int s_x = 0, s_y = 0;

    static inline int PrintCount = 0;

    void Print()
    {
        std::cout << "X:" << x << " Y:" << y << std::endl;
        std::cout << "s_x:" << s_x << " s_y:" << s_y << std::endl;
        std::cout << "PrintCount:" << ++PrintCount << std::endl;
    }

    static void StaticPrint(Entity a)
    {
        std::cout << "X:" << a.x << " Y:" << a.y << std::endl;
        std::cout << "s_x:" << s_x << " s_y:" << s_y << std::endl;
        std::cout << "PrintCount:" << ++PrintCount << std::endl;
    }
};

struct Log
{
// private:
// // With this U cant instanciate the obj 
//     Log(){};
public:
    Log() = delete;
};


// int Entity::s_x;
// int Entity::s_y = 100;
// int Entity::y;

int main()
{
    // Log a;
    // Entity a = {30, 40};

    // Entity b = {10, 20};

    // a.Print();
    std::cout << Entity::PrintCount << std::endl;
    // b.StaticPrint(b);
}