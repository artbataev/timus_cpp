#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> penguin_counter;
    int n;
    std::cin >> n;
    std::cin.ignore(1, '\n');

    std::string penguin;
    for (int i = 0; i < n; i++) {
        getline(std::cin, penguin);
        penguin_counter[penguin]++;
    }

    std::string most_numerous_penguin;
    int max_num_penguin = 0;
    for (const auto&[current_penguin, current_counter]: penguin_counter) {
        if (current_counter > max_num_penguin) {
            max_num_penguin = current_counter;
            most_numerous_penguin = current_penguin;
        }
    }
    std::cout << most_numerous_penguin;
    return 0;
}