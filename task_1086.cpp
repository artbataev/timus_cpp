#include <iostream>
#include <array>
#include <vector>

constexpr int MAX_K = 15'001;
constexpr int SIEVE_LIMIT = 170'000;

int main() {
    std::ios::sync_with_stdio(false);

    std::array<bool, SIEVE_LIMIT> eratosthene_sieve{};
    eratosthene_sieve.fill(true);

    std::vector<int> prime_numbers;
    prime_numbers.reserve(MAX_K);

    for(int i = 2; i < SIEVE_LIMIT; i++)
        if (eratosthene_sieve[i]) {
            prime_numbers.push_back(i);
            int64_t j = i;
            while(i * j < SIEVE_LIMIT) {
                eratosthene_sieve[i * j] = false;
                j++;
            }
        }

    int n;
    int number_in_order;
    std::cin >> n;
    for(int _ = 0; _ < n; _++) {
        std::cin >> number_in_order;
        std::cout << prime_numbers[number_in_order - 1] << std::endl;
    }

    return 0;
}
