#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int num_exams;
    int current_mark;
    int sum_mark = 0;
    bool scholarship_given = true;

    std::cin >> num_exams;
    for(int i = 0; i < num_exams; i++) {
        std::cin >> current_mark;
        scholarship_given = scholarship_given && (current_mark > 3);
        sum_mark += current_mark;
    }

    if(!scholarship_given)
        std::cout << "None";
    else if (sum_mark / num_exams == 5)
        std::cout << "Named";
    else if (static_cast<float>(sum_mark) / num_exams >= 4.5)
        std::cout << "High";
    else
        std::cout << "Common";

    return 0;
}
