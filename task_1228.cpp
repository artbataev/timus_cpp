#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);

    int n;
    int total_elements;
    std::cin >> n >> total_elements;

    int current_d;
    for(int i = 0; i < n; i++) {
        std::cin >> current_d;
        if (i > 0)
            std::cout << " ";
        std::cout << total_elements / current_d - 1;
        total_elements = current_d;
    }

    return 0;
}
