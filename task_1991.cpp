#include <iostream>
#include <vector>

int main() {
    size_t num_blocks; // n
    int num_droids_in_block; // k
    std::cin >> num_blocks >> num_droids_in_block;

    int num_unused_boom_booms = 0;
    int num_droids_survived = 0;
    int current_boom_booms_in_block;
    for (size_t i = 0; i < num_blocks; i++) {
        std::cin >> current_boom_booms_in_block;
        if (current_boom_booms_in_block >= num_droids_in_block) {
            num_unused_boom_booms += current_boom_booms_in_block - num_droids_in_block;
        } else {
            num_droids_survived += num_droids_in_block - current_boom_booms_in_block;
        }
    }
    std::cout << num_unused_boom_booms << " " << num_droids_survived;

    return 0;
}
