#include <iostream>
#include <vector>

int main() {
    int num_can_turn, num_minutes;
    std::cin >> num_can_turn >> num_minutes;

    int total_standing = 0;
    int current_num;

    for (int i = 0; i < num_minutes; i++ ) {
        std::cin >> current_num;
        total_standing = std::max(total_standing + current_num - num_can_turn, 0);
    }
    std::cout << total_standing;

    return 0;
}