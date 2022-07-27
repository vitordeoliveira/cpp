#include <iostream>
#include <string>

int main()
{

    // const char *name0 = u8"Vitor";
    // const char *name = "Vitor";
    // const wchar_t *name2 = L"Vitor";
    // const char16_t *name3 = u"Vitor";
    // const char32_t *name4 = U"Vitor";

    // using namespace std::string_literals;
    // std::string name5 = "vi"s + "tor";
    // std::string name5 = u8"vi"s + "tor";
    // std::wstring name5 = L"vi"s + L"tor";
    // std::u16string name5 = u"vi"s + u"tor";
    // std::u32string name5 = U"vi"s + U"tor";

    const char *exemple = R"(line1
    line2
    line3
    )";

    std::cout << exemple;
}