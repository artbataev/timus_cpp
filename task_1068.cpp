#include <iostream>

int get_sum_1_to_n(const int n) {
    int n_abs = abs(n);
    int result = n_abs * (n_abs + 1) / 2; // from 0 to abs(N)
    if (n <= 0)
        result = -result + 1;
    return result;

}

int main() {
    int n;
    std::cin >> n;

    std::cout << get_sum_1_to_n(n);
    return 0;
}