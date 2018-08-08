#include <iostream>


int main() {
    int berries1_bag1, berries2_bag2;
    std::cin >> berries1_bag1 >> berries2_bag2;

    int berries12_bag1, bag2;
    std::cin >> berries12_bag1 >> bag2;

    int bag1, berries12_bag2;
    std::cin >> bag1 >> berries12_bag2;

    std::cout << (berries1_bag1 - bag1) << " " << (berries2_bag2 - bag2);

    return 0;
}