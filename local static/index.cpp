#include <iostream>

// Local Static is basicaly a global variable with scope.
void Function()
{
    static int i = 0;
    i++;
    std::cout << i << '\n';
}

// class Singleton
// {
// private:
//     static Singleton *s_Instance;

// public:
//     static Singleton &Get(){return *s_Instance;};

//     void Hello()
//     {
//         std::cout << "HELLO" << '\n';
//     }
// };

// Singleton* Singleton::s_Instance = nullptr;

// class Singleton
// {
// private:
//     Singleton *s_Instance;

// public:
//     Singleton &Get(){return *s_Instance;};

//     void Hello()
//     {
//         std::cout << "HELLO" << '\n';
//     }
// };

// Singleton s_Instance;

class Singleton
{
public:
    static Singleton &Get()
    {
        static Singleton instance;
        return instance;
    };

    void Hello()
    {
        std::cout << "HELLO" << '\n';
    }
};

int main()
{
    Function();
    Function();
    Function();
    Function();

    Singleton::Get().Hello();
    // s_Instance.Get().Hello();
}