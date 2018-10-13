#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

bool field_exists(int n, int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int get_num_attacked(int n, int x, int y, const std::string& figure) {
    if (figure == "Queen")
        return get_num_attacked(n, x, y, "Rook") + get_num_attacked(n, x, y, "Bishop");

    if (figure == "Rook")
        return 2 * n - 2;

    if (figure == "Bishop")
        return (n - std::abs(x - y)) + (n - std::abs(x + y - n - 1)) - 2;

    if (figure == "King") {
        int result = 0;
        for (int i = x - 1; i <= x + 1; i++)
            for (int j = y - 1; j <= y + 1; j++)
                result += static_cast<int>(field_exists(n, i, j));
        result--;

        return result;
    }
    if (figure == "Knight") {
        int result = 0;
        for (const auto& x_delta: std::set<int>{-2, -1, 1, 2})
            for (const auto& y_delta: std::set<int>{-2, -1, 1, 2})
                if (std::abs(x_delta) != std::abs(y_delta))
                    result += static_cast<int>(field_exists(n, x + x_delta, y + y_delta));

        return result;
    }

    throw std::logic_error("Unknown figure");
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    int x, y;

    std::cin >> n;
    std::cin >> x >> y;

    std::cout << "King: " << get_num_attacked(n, x, y, "King") << std::endl;
    std::cout << "Knight: " << get_num_attacked(n, x, y, "Knight") << std::endl;
    std::cout << "Bishop: " << get_num_attacked(n, x, y, "Bishop") << std::endl;
    std::cout << "Rook: " << get_num_attacked(n, x, y, "Rook") << std::endl;
    std::cout << "Queen: " << get_num_attacked(n, x, y, "Queen") << std::endl;

    return 0;
}
