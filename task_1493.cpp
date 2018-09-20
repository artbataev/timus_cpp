#include <iostream>

int get_sum_digits(int number) {
    int result = 0;
    while (number != 0) {
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool is_lucky(int number) {
    int left_sum = get_sum_digits(number / 1000);
    int right_sum = get_sum_digits(number % 1000);
    return left_sum == right_sum;
}

int main() {
    std::ios::sync_with_stdio(false);

    int current_ticket;
    std::cin >> current_ticket;
    if (is_lucky(current_ticket - 1) || is_lucky(current_ticket + 1)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}
