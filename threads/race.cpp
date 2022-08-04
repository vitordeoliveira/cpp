#include <basic.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
static bool start = false;
static bool winner = false;

void Car(int num)
{

    using namespace std::literals::chrono_literals;
    int count = 0;

    std::cout << "Car: " << num << " ready\n";

    while (!start)
    {
        std::this_thread::yield();
    }
    while (count < 1000 && !winner)
    {
        std::cout << "count: " << ++count << "\n";
    }

    winner = true;

    std::cout << "Winner is racer number : " << num << "\n";

    exit(0);
}

int main()
{

    std::thread racer(Car, 1);
    std::thread racer2(Car, 2);
    std::thread racer3(Car, 3);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (size_t i = 5; i > 0; i--)
    {
        std::cout << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    start = true;

    std::cin.get();
    return 0;    
}