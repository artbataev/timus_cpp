#include <iostream>
#include <vector>
#include <set>


int main() {
    std::ios::sync_with_stdio(false);

    int period_length;
    std::cin >> period_length;

    std::vector<int> measurements;
    int current_measurement;

    do {
        std::cin >> current_measurement;
        if (current_measurement != -1)
            measurements.push_back(current_measurement);

    } while(current_measurement != -1);

    std::multiset<int> measurements_set(measurements.begin(), measurements.begin() + period_length);
    std::cout << *measurements_set.rbegin() << "\n";

    for(int i = period_length; i < static_cast<int>(measurements.size()); i++) {
        measurements_set.erase(measurements_set.find(measurements[i - period_length]));
        measurements_set.insert(measurements[i]);
        std::cout << *measurements_set.rbegin() << "\n";
    }

    return 0;
}
