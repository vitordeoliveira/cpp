#include <iostream>
#include <string.h>

class String
{
private:
    /* data */
    char *m_Data = nullptr;
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
        printf("Moved1!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        // COMENT NEXT LINE AND TRY TO SOLVE
        // other.m_Data = nullptr;
        // other.m_Size = 0;
    }

    String &operator=(String &&other)
    {
        printf("Moved2!\n");
        if (this != &other)
        {

            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Data = nullptr;
            other.m_Size = 0;
        }

        return *this;
    }

    ~String()
    {
        printf("Destroied!\n");
        delete m_Data;
    }

    void Print()
    {
        if (m_Size != 0)
        {
            for (uint32_t i = 0; i < m_Size; i++)
            {
                printf("%c", m_Data[i]);
            }
        }
        printf("\n");
    }
};

int main()
{

    String apple = "apple";
    // String dest;

    // THIS IS CALLING THE CONSTRUCTOR with the TEMPORARY VALUE
    String dest = std::move(apple); 


    // std::cout << "Apple: ";
    // apple.Print();
    // std::cout << "Dest: ";
    // dest.Print();

    // dest = std::move(apple);

    // std::cout << "Apple: ";
    // apple.Print();
    // std::cout << "Dest: ";
    // dest.Print();
}
