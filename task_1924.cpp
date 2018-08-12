#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    using namespace std::string_literals;
    auto even_wins = "black"s;
    auto odd_wins = "grimy"s;
    if (n * (n + 1) / 2 % 2 == 0) {
        std::cout << even_wins;
    } else {
        std::cout << odd_wins;
    }
    return 0;
}