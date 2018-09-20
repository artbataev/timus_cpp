#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int snow_white_part = 0;
    char c;
    while (std::cin >> c) {
        if (c > '9' || c < '0')
            break;
        snow_white_part = (snow_white_part * 10 + (c - '0')) % 7;
//        std::cout << "get: " << c << " part: " << snow_white_part << std::endl;
    }

    std::cout << snow_white_part;

    return 0;
}
