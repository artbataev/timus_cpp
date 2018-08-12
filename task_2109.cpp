#include <iostream>
#include <cmath>

int get_element(const uint64_t position) {
    // (n + 1) * n / 2 == position - 1, n - Natural or 0 => 1, else 0
    // n ** 2 + n - 2 * (position - 1) == 0
    uint64_t c = - 2 * (position - 1);
    uint64_t discr = 1 - 4 * c; // always > 1 if position > 0
    double discr_sqrt = sqrt(static_cast<double>(discr));
    auto discr_sqrt_int = static_cast<uint64_t>(discr_sqrt);
    if(discr_sqrt_int * discr_sqrt_int == discr && (-1 + discr_sqrt_int) % 2 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;

    uint64_t position;
    for(int i = 0; i < n; i++) {
        std::cin >> position;
        std::cout << get_element(position);
        if (i < n - 1)
            std::cout << " ";
    }

    return 0;
}