#include <basic.h>
#include <thread>

static bool start = false;

void DoWork()
{

    using namespace std::literals::chrono_literals;
    int count  = 0;

        std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";
        std::cout << "Started thread yield = " << std::this_thread::yield << "\n";

    while (count < 5)
    {
        std::cout << "Working \n";
        std::cout << "count: " << ++count << "\n";
        // std::cin.get();
        std::this_thread::sleep_for(1s);
    }
    start = true;
}

void DoWork2()
{

    using namespace std::literals::chrono_literals;
    int count  = 0;

        std::cout << "Started thread id = " << std::this_thread::get_id() << "\n";

    while (!start)
    {
        std::this_thread::yield();
    }
    while (count < 10)
    {
        std::cout << "Working thread 2 \n";
        std::cout << "count: " << ++count << "\n";
        // std::cin.get();
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(DoWork);
    std::thread worker2(DoWork2);
    worker2.join();
    worker.join();


    std::cout << "Out of join \n";

    std::cin.get();
}