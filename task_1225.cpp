#include <iostream>
#include <vector>
#include <array>

const int NUM_COLORS = 3;
// 0 - red
// 1 - white
// 2 - blue

int main() {
    int num_stripes;
    std::cin >> num_stripes;

    std::vector<std::array<uint64_t, 2>> combinations(static_cast<size_t>(num_stripes));
    combinations[0] = {1, 1};
    for(int i = 1; i < num_stripes; i++) {
        for(int last_stripe_color=0; last_stripe_color < 2; last_stripe_color++) {
            combinations[i][last_stripe_color] = combinations[i-1][1 - last_stripe_color];
            if (i > 1) {
                combinations[i][last_stripe_color] += combinations[i - 2][1 - last_stripe_color];
            }
        }
    }

    uint64_t result = combinations[num_stripes - 1][0] + combinations[num_stripes - 1][1];
    std::cout << result;

    return 0;
}