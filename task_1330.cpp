#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    // store cumulative sum instead of numbers
    std::vector<int> intensity_cum_sum(static_cast<size_t>(n));
    for(int i = 0; i < n; i++) {
        std::cin >> intensity_cum_sum[i];
        if (i > 0)
            intensity_cum_sum[i] += intensity_cum_sum[i-1];
    }

    int num_queries;
    std::cin >> num_queries;
    int i, j;
    for(int _ = 0; _ < num_queries; _++) {
        std::cin >> i >> j;
        // 1 <= j <= i <= n, so use j - 1, i - 1
        if (i > 1)
            std::cout << intensity_cum_sum[j - 1] - intensity_cum_sum[i - 1 - 1] << "\n";
        else
            std::cout << intensity_cum_sum[j - 1] << "\n";
    }

    return 0;
}
