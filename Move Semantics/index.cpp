#include <iostream>
#include <string.h>

class String
{
private:
    /* data */
    char *m_Data;
    uint32_t m_Size = 0;

public:
    String() = default;
    String(const char *string)
    {
        printf("Created\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String &other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String &&other)
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        // COMENT NEXT LINE AND TRY TO SOLVE
        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    ~String()
    {
        printf("Destroied!\n");
        // std::cout << m_Size << std::endl;
        // std::cout << m_Data << std::endl;
        delete m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
};

class Entity
{
private:
    String m_Name;

public:
    Entity(const String &name) : m_Name(name)
    {
    }

    // Entity(String &&name) : m_Name((String &&)name)
    // {
    // }

    Entity(String &&name) : m_Name(std::move(name))
    {
    }
    void PrintName()
    {
        m_Name.Print();
    }
};

int main()
{
    // Entity entity("vitor");
    // Entity entity(String("vitor"));

    // entity.PrintName();

    {
        String string = "hello";
        String dest = string;
    }

    {
        String string1 = "hello";
        String dest1 = (String &&) string1;
    }

    {
        String string2 = "hello";
        String dest1 = std::move(string2);
    }
}
