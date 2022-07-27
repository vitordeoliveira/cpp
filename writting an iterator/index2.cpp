#include <iterator>
#include <cstddef>
#include <iostream>

class Integers
{
public:
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = value_type *;
        using reference = value_type &;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator &operator++()
        {
            m_ptr++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Integers()
    {
        for (size_t i = 0; i < 10; i++)
        {
            m_data[i] = 0;
        }
    }

    void operator=(int value)
    {
        std::cout << value << std::endl;
    }
    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[10]); }

private:
    int m_data[10];
};

int main()
{

    Integers integers;

    for (auto i : integers)
        std::cout << i << "\n";
}