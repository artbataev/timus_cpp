#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        if (i != 0) stream << " ";
        stream << numbers[i];
    }
    return stream;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vasya_numbers;
    vasya_numbers.reserve(static_cast<size_t >(n));
    int number;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        vasya_numbers.emplace_back(number);
    }

    std::vector<int> petya_numbers;
    int counter;
    int i = 0;
    while (i < vasya_numbers.size()) {
        number = vasya_numbers[i];
        counter = 1;
        i++;
        while (i < vasya_numbers.size() && vasya_numbers[i] == number) {
            counter++;
            i++;
        }
        petya_numbers.emplace_back(counter);
        petya_numbers.emplace_back(number);
    }
    std::cout << petya_numbers;

    return 0;
}