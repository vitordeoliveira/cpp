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
};

main()
{
    // int size = 5;
    // std::array<int, 10> collection;
    Array<int, 3> data;
    data[0] = 0;
    data[1] = 1;
    data[2] = 2;

    // memset(data.Data(), 0, data.Size() * sizeof(int));
    memset(&data[0], 0, data.Size() * sizeof(int));
    static_assert(data.Size() < 10, "Size is too large");

    // Array<std::string, data.Size()> newArray;
    const Array<int, 3> constdata = data;

    for (size_t i = 0; i < data.Size(); i++)
    {
        std::cout << constdata[i] << std::endl;
    }
}