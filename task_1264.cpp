#include <iostream>


int main() {
    int64_t array_size, max_number;
    std::cin >> array_size >> max_number;
    std::cout << array_size * (max_number + 1);

    return 0;
}