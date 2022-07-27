#pragma once

template <typename T>
constexpr bool is_lvalue(T &)
{
    return true;
}

template <typename T>
constexpr bool is_lvalue(T &&)
{
    return false;
}

template <typename Vector>
class VectorIterator
{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;
    VectorIterator(PointerType ptr)
        : m_Ptr(ptr)
    {
    }

    VectorIterator &operator++()
    {
        m_Ptr++;
        return *this;
    }

    VectorIterator &operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator &operator--()
    {
        m_Ptr--;
        return *this;
    }

    VectorIterator &operator--(int)
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index)
    {
        return *(m_Ptr + index);
    }

    ReferenceType operator*()
    {
        return *m_Ptr;
    }

    PointerType operator->()
    {
        return m_Ptr;
    }

    bool operator==(const VectorIterator &other) const
    {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator &other) const
    {
        return !(*this == other);
    }

private:
    PointerType m_Ptr;
};

template <typename T>
class Vector
{
private:
    T *m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void ReAlloc(size_t newCapacity)
    {
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete

        // T *newBlock = new T[newCapacity];
        T *newBlock = (T *)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_Size)
        {
            m_Size = newCapacity;
        }

        for (size_t i = 0; i < m_Size; i++)
        {
            // newBlock[i] = std::move(m_Data[i]);
            new (&newBlock[i]) T(std::move(m_Data[i]));
        }

        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }

        // delete[] m_Data;
        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;

    Vector(/* args */)
    {
        ReAlloc(2);
    }

    ~Vector()
    {
        printf("Destroyed VECTOR\n");
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T &value)
    {
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        // m_Data[m_Size++] = value;
        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T &&value)
    {
        // std::cout << "Is value a lValue ? " << '\n';
        // std::cout << "a : " << is_lvalue(value) << '\n';

        // std::cout << "Is lValue ? " << '\n';
        // std::cout << "a : " << is_lvalue(std::move(value)) << '\n';

        // &&value become an lvalue when enter in the function

        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        m_Data[m_Size++] = std::move(value);
        // m_Data[m_Size] = std::move(value);
        // m_Size++;
    }

    template <typename... Args>
    T &EmplaceBack(Args &&...args)
    {
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }

        new (&m_Data[m_Size]) T(std::forward<Args>(args)...);

        // m_Data[m_Size] = T(std::forward<Args>(args)...);

        return m_Data[m_Size++];
    }

    void popBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
        {
            /* code */
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    const T &operator[](size_t index) const
    {

        return m_Data[index];
    }

    T &operator[](size_t index)
    {
        return m_Data[index];
    }

    size_t Size() const { return m_Size; }

    // FOR RANGED BASE ITERATOR HE ONLY NEED A BEGIN AND END;
    Iterator begin()
    {
        return Iterator(m_Data);
    }

    Iterator end()
    {
        return Iterator(m_Data + m_Size);
    }
};
