#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        duration = std::chrono::high_resolution_clock::now() - start;

        float ms = duration.count() * 1000.0f;

        std::cout << "Timer took " << ms << "ms\n";
    }
};

void Function()
{

    Timer timer;
    for (size_t i = 0; i < 100000; i++)
    {
        std::cout << i << "\n";
    }
}

int main()
{

    Function();
}