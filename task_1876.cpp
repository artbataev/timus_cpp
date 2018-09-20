#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int num_left_slippers; // >= 40
    int num_right_slippers; // >= 40
    std::cin >> num_left_slippers >> num_right_slippers;

    int max_seconds_no_turn = 40 * 2 + (num_right_slippers - 40) * 2 + 40;
    // all right slippers first, then remaining right slippers, then left slippers
    int max_seconds_with_turn = 39 * 2 + 40 + 2 * (num_left_slippers - 40) + 1;
    // 39 right slippers, all left slippers <-turn-> then remaining left slippers, then 1 right slipper

    int max_seconds = std::max(max_seconds_no_turn, max_seconds_with_turn);
    std::cout << max_seconds;

    return 0;
}
