#include <iostream>
#include <string>

//bool is_even(std::string_view s) { // can't compile using acm.timus.ru, but actually works
bool is_even(const std::string& s) {
    int last_elem = s[s.size() - 1] - '0';
    return last_elem % 2 == 0;
}

int main() {
    std::string code1;
    std::string code2;

    std::cin >> code1 >> code2;
    if (is_even(code1) or !is_even(code2)) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}