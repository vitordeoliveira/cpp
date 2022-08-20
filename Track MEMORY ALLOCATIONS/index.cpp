#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void *operator new(size_t size)
{
    std::cout << "Allocating " << size << " Bytes\n";
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void *memory, size_t size)
{
    std::cout << "Free " << size << " Bytes\n";
    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}
 
struct Object
{
    int x, y, z;

    // void *operator new(size_t size)
    // {
    //     std::cout << "Allocating 2 " << size << " Bytes\n";
    //     s_AllocationMetrics.TotalAllocated += size;
    //     return malloc(size);
    // }
};

int main()
{
    std::cout << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;

    Object _obj; // Stack

    Object *obj = new Object;  // Heap
    Object *obj1 = new Object; // Heap
    std::cout << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
    delete obj;

    std::cout << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;

    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        std::cout << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
    }

    std::cout << s_AllocationMetrics.CurrentUsage() << " bytes" << std::endl;
}