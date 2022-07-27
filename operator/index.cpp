#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Vector
{
    int x, y;

    Vector(int x, int y) : x(x), y(y) {}

    Vector Add(const Vector &other) const
    {
        // return Vector(x + other.x, y + other.y);
        // return *this + other;
        return operator+(other);
    }

    Vector Multiply(const Vector &other) const
    {
        return Vector(x * other.x, y * other.y);
    }

    Vector operator+(const Vector &other) const
    {
        // return Add(other);
        return Vector(x + other.x, y + other.y);
    }

    Vector operator*(const Vector &other) const
    {
        // Vector(x * other.x, y * other.y)
        return Multiply(other);
    }

    Vector operator<<(const Vector &other) const
    {
        // Vector(x * other.x, y * other.y)
        return Multiply(other);
    }

    bool operator==(const Vector &other) const
    {
        return x == other.x and y == other.y;
    }

    bool operator!=(const Vector &other) const
    {
        // return !(operator==(other));
        return !(*this == other);
    }

    void operator()(const std::string __k, const Vector &other)
    {
        // return !(operator==(other));
        std::cout << __k << ": " << other.x << std::endl;
    }

    // friend void operator<(const Vector &other, const Vector &other2)
    // {
    //     std::cout << other.x << ": " << other2.y << std::endl;
    // }

    void operator<(const Vector &other2)
    {
        std::cout << x << ": " << other2.y << std::endl;
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector &other)
{
    stream << other.x << ", " << other.y;

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const std::vector<int> &other)
{
    std::stringstream str;
    for (auto x : other)
    {
        str << x << " ";
    }
    stream << str.str();

    return stream;
}

int main()
{
    Vector position(4, 3);
    Vector speed(4, 3);
    Vector powerup(4, 3);

    Vector result = position.Add(speed.Multiply(powerup));
    Vector result2 = position + speed * powerup;

    result2 = position << speed;

    std::cout << "result: " << result << std::endl;
    std::cout << "result2: " << result2 << std::endl;
    std::cout << result2.y << std::endl;

    std::cout << result << std::endl;
    std::vector<int> test = {1, 2, 35, 6};

    std::cout << test << std::endl;

    result2("p", result2);
    result2 < result;
}