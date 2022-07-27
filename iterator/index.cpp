#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

int main()
{
    std::vector<int> values = {1, 23, 4, 4, 5, 6};

    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }

    for (int x : values)
    {
        std::cout << x << std::endl;
    }

    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    using ScoreMap = std::unordered_map<std::string, int>;
    // using ScoreMapConstIter = ScoreMap::const_iterator;

    ScoreMap map;
    map["Vitor"] = 5;
    map["C++"] = 2;

    // for(std::unordered_map<std::string, int>::const_iterator)
    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto &key = it->first;
        auto &value = it->second;

        std::cout << key << ": " << value << std::endl;
    }

    for (auto kv : map)
    {
        auto &key = kv.first;
        auto &value = kv.second;

        std::cout << key << ": " << value << std::endl;
    }

    for (auto [key, value] : map)
    {

        std::cout << key << ": " << value << std::endl;
    }
    // for(ScoreMapConstIter)
}