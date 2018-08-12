#include <iostream>
#include <string>

bool first_wins(int rows, int cols) {
    return ((rows - 1) + rows * (cols - 1)) % 2 != 0;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    using namespace std::string_literals;
    const auto KARLSON_SHOULD_START = "[:=[first]"s;
    const auto KARLSON_SHOULD_NOT_START = "[second]=:]"s;

    if (first_wins(rows, cols)) {
        std::cout << KARLSON_SHOULD_START;
    } else {
        std::cout << KARLSON_SHOULD_NOT_START;
    }


    return 0;
}