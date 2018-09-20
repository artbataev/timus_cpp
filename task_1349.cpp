#include <iostream>
#include <cmath>


int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << -1;
    } else if (n == 1) {
        std::cout << "1 2 3";
    } else if (n == 2) {
        std::cout << "3 4 5";
    } else { // n > 3,
        std::cout << -1; // Fermat's Last Theorem
    }

    return 0;
}
