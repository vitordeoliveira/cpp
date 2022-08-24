#include <iostream>
#include <vector>
#include <functional>
#include <string>

// void ForEach(const std::vector<int> &values, void (*func)(int))
// {
//     for (int value : values)
//     {
//         func(value);
//     }
// }

void ForEach(const std::vector<int> &values, const std::function<void(int)> &func)
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values2 = {1, 2, 3, 45, 6};
    ForEach(values2, [](int value)
            { std::cout << value << std::endl; });

    const int a = 10;
    int b = a;
    std::cout << "value2" << std::endl;
    ForEach({1, 23, 4}, [a](int value)
            {std::cout << value << std::endl; std::cout << a << std::endl; });

    std::cout << "value3" << std::endl;
    ForEach({1, 23, 4}, [b](int value) mutable
            { b = 90; std::cout << value << std::endl; std::cout << a << std::endl; });

    std::cout << "value4" << std::endl;


    auto it = std::find_if(values2.begin(), values2.end(), [](int value)
                           { return value > 5; });

    std::cout << *it << "\n";
}