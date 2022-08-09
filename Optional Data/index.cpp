#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <sstream>
#define opt std::optional

// opt<std::string> ReadFileAsString(const std::string &filepath)
// {
//     std::ifstream stream(filepath);
//     if (stream.is_open())
//     {
//         // std::stringstream result;
//         // result << stream.rdbuf();
//         std::string result((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

//         stream.close();

//         return result;
//     }

//     return {};
// }

opt<std::string> ReadFileAsString(const std::string &filepath)
{
    std::ifstream stream(filepath);
    if (stream.is_open())
    {
        std::string result;

        while (!stream.eof())
        {
            char v = stream.get();
            if(v != -1)  std::cout << "Current character is: " << v << std::endl;
        }

        // while (stream.good())
        // {
        //     char v = stream.get();
        //     if(v != -1)  std::cout << "Current character is: " << v << std::endl;
        // }


        // for (char c; stream.get(c);)
        // {
        //     std::cout << "Current character is: " << c << std::endl;
        // }

        // std::cout << stream.rdbuf();

        stream.close();

        return result;
    }

    return {};
}

int main()
{

    opt<std::string> data = ReadFileAsString("data.txt");

    // std::string value = data.value_or("Not present");
    // // std::cout << value << "\n";

    // opt<int> count;
    // int c = count.value_or(100);

    // // if(data.has_value()){
    // if (data)
    // {
    //     std::cout << "file read successfully! \n";
    //     std::string &string = *data;
    //     std::cout << data.value() << "\n";

    //     // data->
    // }
    // else
    // {
    //     std::cout << "file could not be opened! \n";
    // }
}