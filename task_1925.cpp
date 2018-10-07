#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    int shown_number, entered_number;
    int shown_numbers_sum = k;
    int entered_numbers_sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> shown_number >> entered_number;
        shown_numbers_sum += shown_number;
        entered_numbers_sum += entered_number;
    }

    int need_to_enter = shown_numbers_sum - 2 * (n + 1) - entered_numbers_sum;

    if(need_to_enter >= 0)
        std::cout << need_to_enter;
    else
        std::cout << "Big Bang!";

    return 0;
}
