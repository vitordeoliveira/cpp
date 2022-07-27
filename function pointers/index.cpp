#include <iostream>
#include <vector>
#include <string>

void print(const std::string &text)
{
    std::cout << "----------------" << std::endl
              << text << std::endl
              << "----------------" << std::endl;
}

void HelloWorld()
{
    std::cout << "hello world" << std::endl;
}

void HelloWorld2(int a)
{
    std::cout << "hello world "
              << "VALUE: " << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << value << std::endl;
}

void ForEach(const std::vector<int> &values, void (*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    print("PART 1");
    HelloWorld();

    // auto function = &HelloWorld;
    auto function = HelloWorld;
    function();
    print("PART 2");
    // PART 2
    void (*function2)() = HelloWorld;
    function2();

    // PART 3
    print("PART 3");
    typedef void (*HelloWorldFunction)();
    HelloWorldFunction function3 = HelloWorld;
    function3();

    // PART 4
    print("PART 4");
    auto function4 = HelloWorld2;
    function4(1);

    void (*function5)(int x) = HelloWorld2;
    function5(2);

    typedef void (*HelloWorldFunction2)(int y);
    HelloWorldFunction2 function6 = HelloWorld2;
    function6(3);

    // PART 5
    print("PART 5");

    std::vector<int> values = {1, 2, 3, 45, 6};
    ForEach(values, PrintValue);

    // PART 6
    print("PART 6");

    std::vector<int> values2 = {1, 2, 3, 45, 6};
    ForEach(values2, [](int value)
            { std::cout << value << std::endl; });
}