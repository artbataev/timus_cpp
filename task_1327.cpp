#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int start_day;
    int end_day;
    std::cin >> start_day >> end_day;

    int fuses_blown = (end_day + 1) / 2 - (start_day - 1 + 1) / 2;
    std::cout << fuses_blown << std::endl;
    return 0;
}
