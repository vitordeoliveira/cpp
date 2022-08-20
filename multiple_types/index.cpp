#include <iostream>
#include <variant>
#include <string>
#include <optional>

std::optional<std::string> Reas()
{
    return {};
}

enum class ErrorCode
{
    None = 0,
    NotFound = 1,
    NoAccess = 2
};

std::variant<std::string, ErrorCode> Read()
{
    return {};
}

int main()
{
    std::variant<std::string, int> data;

    data = "vitor";
    std::cout << std::get<std::string>(data) << "\n";
    data = 23;
    void *ptr;

    if (auto value = std::get_if<std::string>(&data))
    {
        std::string &v = *value;
    }

    // if (auto v = 10; v == 5)
    // {
    //     std::cout << "v: " << v << "\n";
    // }

    std::cout << std::get<int>(data) << "\n";
}