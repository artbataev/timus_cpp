#include <iostream>

int main() {
    int cans_Harry, cans_Larry;
    std::cin >> cans_Harry >> cans_Larry;
    int all_cans = cans_Harry + cans_Larry - 1;
    int cans_not_Harry = all_cans - cans_Harry;
    int cans_not_Larry = all_cans - cans_Larry;
    std::cout << cans_not_Harry << " " << cans_not_Larry;
    return 0;
}