#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> prev_row(static_cast<size_t>(m));
    std::vector<int> current_row(static_cast<size_t>(m));

    bool all_rectangles = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> current_row[j];
            if (i > 0 && j > 0 && (current_row[j - 1] + current_row[j] + prev_row[j - 1] + prev_row[j] == 3)) {
                all_rectangles = false;
                break;
            }
        }
        if (!all_rectangles)
            break;
        std::swap(prev_row, current_row);
    }

    if (all_rectangles)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}

