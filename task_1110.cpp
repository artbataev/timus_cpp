#include <iostream>

int x_pow_n_mod_m(int x, int n, int m) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        result = (result * x) % m;
        if (result == 0)
            break;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, y;
    std::cin >> n >> m >> y;
    bool found = false;

    for(int i = 0; i < m; i++) {
        if (x_pow_n_mod_m(i, n, m) == y) {
            if(found)
                std::cout << " ";
            found = true;
            std::cout << i;
        }
    }
    if (!found)
        std::cout << -1;

    return 0;
}
