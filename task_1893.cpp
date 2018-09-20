#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int row;
    char position;
    std::cin >> row >> position;

    if (row <= 2) { // premium class
        if (position == 'A' || position == 'D')
            std::cout << "window";
        else
            std::cout << "aisle";
    } else if (row <= 20) { // business class
        if (position == 'A' || position == 'F')
            std::cout << "window";
        else
            std::cout << "aisle";
    } else { // row >= 21, economy class
        int seat_num = position < 'I' ? 1 + position - 'A' : 1 + position - 'A' - 1;
        if (seat_num == 1 || seat_num == 10)
            std::cout << "window";
        else if (seat_num == 3 || seat_num == 4 || seat_num == 7 || seat_num == 8)
            std::cout << "aisle";
        else
            std::cout << "neither";
    }

    return 0;
}
