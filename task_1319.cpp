#include <iostream>

int get_number_reversed_by_counter_diagonal(const int i, const int j, const int n) {
    int diag_num = n + i - j;
    int prev_diag_num = diag_num - 1;
    int numbers_used_above_diag = 0;
    if (prev_diag_num <= n) {
        numbers_used_above_diag = prev_diag_num * (prev_diag_num + 1) / 2;
    } else {
        numbers_used_above_diag = n * (n + 1) / 2;
        numbers_used_above_diag += (prev_diag_num - n) * (2 * n - prev_diag_num + n - 1) / 2;
    }
    int current_number = numbers_used_above_diag;
    if (diag_num <= n) {
        current_number += i + 1;
    } else {
        current_number += j + 1;
    }

    return current_number;
}

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << get_number_reversed_by_counter_diagonal(i, j, n);
            if(j < n - 1) {
                std::cout << " ";
            } else if(i < n - 1) {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}