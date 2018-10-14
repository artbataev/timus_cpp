#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int current_denomination;
    int can_represent_max = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> current_denomination;
        if (can_represent_max + 1 < current_denomination)
            break;
        can_represent_max += current_denomination;
    }

    std::cout << can_represent_max + 1;

    return 0;
}

