#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> monitor(static_cast<size_t>(n));
    int elem;

    for(int i = 0; i < n; i++) {
        monitor[i].reserve(static_cast<size_t>(n));
        for(int j = 0; j < n; j++) {
            std::cin >> elem;
            monitor[i].push_back(elem);
        }
    }

    for (int diag = 0; diag < (2 * n - 1); diag++) {
        int i = std::min(diag, n - 1);
        int j = std::max(0, diag - (n - 1));
        while(i >= 0 and j < n) {
            std::cout << monitor[i][j];
            if (diag < (2 * n - 1)) std::cout << " ";
            i--;
            j++;
        }
    }
    return 0;
}