#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 99'999;

int main() {
    std::ios::sync_with_stdio(false);

    std::vector<int> a(static_cast<size_t>(MAX_N + 1));
    a[0] = 0;
    a[1] = 1;
    for(int i = 0; i <= MAX_N; i++)
        if(i % 2 == 0)
            a[i] = a[i / 2];
        else
            a[i] = a[i / 2] + a[i / 2 + 1];

    int n;
    do {
        std::cin >> n;
        if (n != 0)
            std::cout << *std::max_element(a.begin(), a.begin() + n + 1) << "\n";
    } while(n != 0);

    return 0;
}
