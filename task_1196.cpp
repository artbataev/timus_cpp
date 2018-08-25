#include <iostream>
#include <algorithm>
#include <unordered_set>

int main() {
    size_t num_professor_dates;
    std::cin >> num_professor_dates;

    std::unordered_set<int> professor_dates;
    professor_dates.reserve(num_professor_dates);
    int current_date;
    for (size_t i = 0; i < num_professor_dates; i++) {
        std::cin >> current_date;
        professor_dates.insert(current_date);
    }

    size_t num_student_dates;
    size_t num_dates_in_all_lists = 0;
    std::cin >> num_student_dates;
    for (size_t i = 0; i < num_student_dates; i++) {
//        std::cin >> current_date;
        scanf("%d", &current_date); // this is 1.5x faster!
        if (professor_dates.count(current_date) > 0) {
            num_dates_in_all_lists++;
        }
    }
    std::cout << num_dates_in_all_lists;

    return 0;
}
