#include <iostream>
#include <string>
#include <fstream>

std::string ReadFileAsString(const std::string &filepath)
{
    std::ifstream stream(filepath);
    if (stream.is_open())
    {
        std::string result;

        while (!stream.eof())
        {
            char v = stream.get();
            // if(v != -1)  std::cout << "Current character is: " << v << std::endl;
            if (v != -1)
                result += v;
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

    return "";
}

void WriteFileAsString(std::string filename, std::string data)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << data;
        file.close();
    }
    else
        std::cout << "Unable to open file";
}

int main()
{
    WriteFileAsString("test.json", "{\n\t\"name\":\"Vitor de Oliveira\",\n\t\"country\":\"Brazil\"\n}");
    auto data = ReadFileAsString("test.json");

    std::cout << data << "\n";
}