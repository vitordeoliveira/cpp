#include "../BasicIncludes.h"
#include "../vector/Vector.h"
#include "../array/Array.h"
#include <algorithm>    // std::fill
int main()
{
    // Vector<std::string> values;

    // values.EmplaceBack("1");
    // values.EmplaceBack("2");
    // values.EmplaceBack("3");
    // values.EmplaceBack("4");
    // values.EmplaceBack("5");

    // std::cout << "Not using iterators: \n";
    // for (size_t i = 0; i < values.Size(); i++)
    // {
    //     std::cout << values[i] << std::endl;
    // }

    // std::cout << "Ranged Base iterator: \n";
    // for (auto x : values)
    // {
    //     std::cout << x << std::endl;
    // }

    // std::cout << "Iterator: \n";
    // for (Vector<std::string>::Iterator it = values.begin(); it!= values.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    Array<int, 3> data;
    // data[0] = 0;
    // data[1] = 1;
    // data[2] = 90;

    std::fill(data.begin(), data.end(), 10);

    for (auto x : data)
    {
        std::cout << x << std::endl;
    }

    std::cout << "Iterator: \n";
    for (auto it = data.begin(); it != data.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
