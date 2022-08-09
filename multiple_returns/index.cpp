// #include <tuple>
// #include <iostream>

// std::tuple<int, int> returntwovalues(int a, int b) {
//     return  {a, b};
// }

// auto returntwovalues2(int a, int b) {
//     struct result {int a; int b;};
//     return result {a, b};
// }



// int main() {
//     using namespace std;

//     auto [quotient, remainder] = returntwovalues(14, 3);

//     cout << quotient << ',' << remainder << endl;
// }





#include <tuple>

std::tuple<int, int> returntwovalues(int a, int b) {
    return  std::make_tuple(a, b);
}

#include <iostream>

template <typename... Args>
constexpr // since C++14
std::tuple<Args&...> bla(Args&... args) noexcept {
    return {args...};
}

int main() {
    using namespace std;

    int quotient, remainder;

    bla(quotient, remainder) = returntwovalues(14, 3);

    cout << quotient << ',' << remainder << endl;
}