#include <iostream>

int main() {
    int n;
    int a;
    int b;
    std::cin >> n >> a >> b;
    auto total_weight = n * a * b * 2;
    std::cout << total_weight;
    return 0;
}