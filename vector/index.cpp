#include <iostream>
#include "../array/Array.h"
#include "Vector.h"

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int *m_MemoryBlock = nullptr;

    Vector3() { m_MemoryBlock = new int[5]; };
    Vector3(float scalar) : x(scalar), y(scalar), z(scalar)
    {
        m_MemoryBlock = new int[5];
    };
    Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
        m_MemoryBlock = new int[5];
    };

    Vector3(const Vector3 &other) = delete;
    // : x(other.x), y(other.y), z(other.z)
    // {
    //     std::cout << "Copy\n";
    // }

    Vector3(Vector3 &&other) : x(other.x), y(other.y), z(other.z)
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        std::cout << "Move\n";
    }

    ~Vector3()
    {
        std::cout << "Destroy\n";
        delete[] m_MemoryBlock;
    }

    Vector3 &operator=(const Vector3 &other) = delete;
    // {
    //     std::cout << "Copy\n";
    //     x = other.x;
    //     y = other.y;
    //     z = other.z;

    //     return *this;
    // }
    Vector3 &operator=(Vector3 &&other)
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        std::cout << "Move\n";
        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }
};

template <typename T>
void Print(const Vector<T> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

template <>
void Print(const Vector<Vector3> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

int main()
{
    // Array<std::string, 2> data;
    // data[0] = "vitor";
    // data[1] = "c++";

    Vector<std::string> vector;
    vector.EmplaceBack("Vitor");
    // vector.PushBack("Mariana");
    // vector.PushBack("Milka");
    // vector.PushBack("Tecnology");
    // vector.PushBack("C++");
    // vector.PushBack("Vector");

    // Print(vector);

    {
        Vector<Vector3> vector3;
        // Vector3 test = Vector3{1, 2, 3};
        // vector3.PushBack(Vector3{1.0f});
        // vector3.PushBack(Vector3{1, 2, 3});
        // vector3.PushBack(Vector3());
        vector3.EmplaceBack(1, 2, 3);
        vector3.EmplaceBack(1, 2, 3);

        // vector3.popBack();
        Print(vector3);
    }
}