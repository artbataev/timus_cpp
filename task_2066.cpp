#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int result;
    if (b > 1) {
        result = a - b * c;
    } else {
        // if b == 1 it is better to do (a - b) - c
        // b == 0 => a == 0, because a <= b <= c;
        result = a - b - c;
    }
    std::cout << result;

    return 0;
}