#include <iostream>
#include <string>
#include <set>
#include <map>
#include <array>


int main() {
    std::ios::sync_with_stdio(false);

    std::map<std::string, int> reagents_by_color;
    std::cin >> reagents_by_color["Blue"] >> reagents_by_color["Red"] >> reagents_by_color["Yellow"];

    int num_reagents;
    std::cin >> num_reagents;

    std::set<std::string> required_colors;
    std::string current_color;
    for (int _ = 0; _ < num_reagents; _++) {
        std::cin >> current_color;
        required_colors.insert(current_color);
    }

    int total_combinations = 1;
    for (const auto& color: required_colors) {
        total_combinations *= reagents_by_color[color];
    }


    std::cout << total_combinations;

    return 0;
}
