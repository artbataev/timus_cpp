#include <iostream>
#include <set>
#include <limits>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);

    std::set<int64_t> piles;
    int64_t x;
    for (int _ = 0; _ < 3; _++) {
        std::cin >> x;
        piles.insert(x);
    }

    int num_aborigines = 0;
    int64_t min_difference;
    int64_t prev;

    while (true) {
        num_aborigines++;

        prev = -1;
        min_difference = std::numeric_limits<int64_t>::max();
        // count min_difference using sorted numbers
        for (const auto& pile: piles) {
            if (prev != -1)
                min_difference = std::min(min_difference, pile - prev);
            prev = pile;
        }

        if (piles.count(min_difference) == 0)
            piles.insert(min_difference);
        else {
            num_aborigines++; // next aborigine will point on these piles
            break;
        }
    }

    std::cout << num_aborigines;
    return 0;
}
