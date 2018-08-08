#include <iostream>

int constexpr get_minutes(const int num_steaks, const int max_cooked_simultaneously) {
    if (num_steaks < max_cooked_simultaneously)
        return 2;
    int num_minutes = (num_steaks * 2 + max_cooked_simultaneously - 1) / max_cooked_simultaneously;
    return num_minutes;
}

int main() {
    static_assert(get_minutes(1, 2) == 2, "1, 2 -> 2");
    static_assert(get_minutes(3, 2) == 3, "3, 2 -> 3, from task");

    int num_steaks, max_cooked_simultaneously;
    std::cin >> num_steaks >> max_cooked_simultaneously;

    std::cout << get_minutes(num_steaks, max_cooked_simultaneously);

    return 0;
}