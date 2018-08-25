#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    size_t num_candidates, num_electors;
    std::cin >> num_candidates >> num_electors;
    std::vector<double> votes(num_candidates + 1); // from 1 to num_candidates
    int current_candidate;

    for(size_t i = 0; i < num_electors; i++) {
        std::cin >> current_candidate;
        votes[current_candidate] += 1.0;
    }

    for(size_t i = 1; i <= num_candidates; i++) {
        votes[i] = votes[i] * 100.0 / num_electors;
    }

    std::cout << std::fixed << std::setprecision(2);
    for(size_t i = 1; i <= num_candidates; i++) {
        std::cout << votes[i] << "%" << std::endl;
    }

    return 0;
}
