#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>

std::vector<double> read_numbers(std::istream& from) {
    std::vector<double> numbers;
    double tmp;
    while(from >> tmp) {
        numbers.push_back(tmp);
    }
    return numbers;
}

void print_numbers(const std::vector<double>& numbers, std::ostream &to) {
    to << std::fixed << std::setprecision(4);
    for (const auto &number:numbers) {
        to << number << std::endl;
    }
}

int main() {
//    std::fstream from_file("../data/input_1001_1.txt");
//    auto& from = from_file;
    auto& from = std::cin;

    std::vector<double> numbers = std::move(read_numbers(from));

    std::vector<double> sqrt_numbers(numbers.rbegin(), numbers.rend());
    for (auto &number:sqrt_numbers) {
        number = std::sqrt(number);
    }

    print_numbers(sqrt_numbers, std::cout);
    return 0;
}