#include <iostream>
#include <array>

constexpr int MAX_SUM_DIGITS = 81;
constexpr int MAX_NUM_DIGITS = 9;

int main() {
    std::ios::sync_with_stdio(false);

    std::array<std::array<int, MAX_SUM_DIGITS + 1>, MAX_NUM_DIGITS + 1> numdigis_sumdigits_count{};

    int required_sum_digits;
    std::cin >> required_sum_digits;
    for (int sum_digits = 1; sum_digits <= required_sum_digits; sum_digits++) {
        if (sum_digits <= 9)
            numdigis_sumdigits_count[1][sum_digits] = 1;

        for (int num_digits = 2; num_digits <= MAX_NUM_DIGITS; num_digits++)
            for (int additional_digit = 0; additional_digit <= 9; additional_digit++)
                if (sum_digits - additional_digit >= 0) {
                    numdigis_sumdigits_count[num_digits][sum_digits] +=
                            numdigis_sumdigits_count[num_digits - 1][sum_digits - additional_digit];
                }
    }

    int full_num_digits = 0;
    for (int num_digits = 1; num_digits <= MAX_NUM_DIGITS; num_digits++)
        full_num_digits += numdigis_sumdigits_count[num_digits][required_sum_digits];
    if (required_sum_digits == 1) // count 10**9
        full_num_digits++;

    std::cout << full_num_digits;

    return 0;
}
