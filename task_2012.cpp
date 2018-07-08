#include <iostream>

int main() {
    int num_problems_to_solve_first_hour;
    std::cin >> num_problems_to_solve_first_hour;
    const int num_problems_to_solve_last_4_hours = 60 * 4 / 45;
    auto num_problems_will_be_solved = num_problems_to_solve_first_hour + num_problems_to_solve_last_4_hours;
    num_problems_will_be_solved < 12 ? std::cout << "NO" : std::cout << "YES";

    return 0;
}
