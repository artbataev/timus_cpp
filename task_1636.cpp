#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int time_1, time_2;
    std::cin >> time_1 >> time_2;

    int time_penalty = 0;
    int num_rejected_runs;
    for(int i = 0; i < 10; i++) {
        std::cin >> num_rejected_runs;
        time_penalty += num_rejected_runs * 20;
    }

    if (time_2 - time_penalty >= time_1)
        std::cout << "No chance.";
    else
        std::cout << "Dirty debug :(";

    return 0;
}
