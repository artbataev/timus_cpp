#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> forces(static_cast<size_t>(n));

    for(int i = 0; i < n; i++) {
        std::cin >> forces[i];
    }
    int max_force = 0; // all forces > 0
    int max_force_position = -1;
    for(int i = 1; i < n - 1; i++) {
        if (int current_force = forces[i-1] + forces[i] + forces[i+1]; current_force > max_force) {
            max_force = current_force;
            max_force_position = i + 1; // position – from 1 to n
        }
    }
    std::cout << max_force << " " << max_force_position;
    return 0;
}