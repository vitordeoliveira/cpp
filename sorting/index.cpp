#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = {2, 5, 7, 4, 3, 7, 9, 1, 4};

    // std::sort(values.begin(), values.end());
    // std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b)
              { if(a==1) return false;
              if(b==1) return true; 
              return a < b; });

    for (auto x : values)
    {
        std::cout << x << "\n";
    }
}