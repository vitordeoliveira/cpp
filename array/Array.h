#include <iostream>
#include <array>
#include <string.h>

template <typename T, size_t S>
class Array
{
private:
    // int m_Data[1];
    // int *m_Data;
    T m_Data[S];

public:
    struct Iterator
    {

        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;
        Iterator(pointer ptr) : m_ptr(ptr){};

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

    Array(){};
    // Array(int size){
    //     // m_Data = (int *)alloca(size * sizeof(int));
    // };
    constexpr size_t Size() const { return S; }

    T &operator[](size_t index)
    {
        return m_Data[index];
    }

    const T &operator[](size_t index) const
    {
        return m_Data[index];
    }

    T *Data() { return m_Data; }
    // T *Data() { return *m_Data; }

    Iterator begin() { return Iterator(m_Data); }
    Iterator end() { return Iterator(m_Data + S); }
};