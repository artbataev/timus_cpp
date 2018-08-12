#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

const std::map<std::string, int> NAME2CASE {
        {"Alice", 0},
        {"Ariel", 0},
        {"Aurora", 0},
        {"Bambi", 1},
        {"Belle", 1},
        {"Bolt", 1},
        {"Dumbo", 2},
        {"Genie", 2},
        {"Jiminy", 2},
        {"Phil", 0},
        {"Peter", 0},
        {"Olaf", 0},
        {"Mulan", 1},
        {"Mowgli", 1},
        {"Mickey", 1},
        {"Kuzko", 2},
        {"Kida", 2},
        {"Kenai", 2},
        {"Phoebus", 0},
        {"Ralph", 0},
        {"Robin", 0},
        {"Silver", 1},
        {"Simba", 1},
        {"Stitch", 1},
        {"Tarzan", 2},
        {"Tiana", 2},
        {"Winnie", 2},
};


int main() {
    int n;
    std::cin >> n;
    int total_steps = 0;
    int current_position = 0;
    std::string current_name;
    for (int i = 0; i < n; i++) {
        std::cin >> current_name;
        total_steps += abs(current_position - NAME2CASE.at(current_name));
        current_position = NAME2CASE.at(current_name);
    }
    std::cout << total_steps;

    return 0;
}