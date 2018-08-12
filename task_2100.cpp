#include <iostream>
#include <string>
#include <algorithm>

inline bool ends_with(const std::string & s, const std::string & ending) {
    if (s.size() < ending.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), s.rbegin());
}

int main() {
    int num_invitations;
    std::cin >> num_invitations;
    int num_people = num_invitations + 2; // Marshall and Lily
    std::string name;
    for (int i = 0; i < num_invitations; i++) {
        std::cin >> name;
        num_people += ends_with(name, "+one");
    }
    if (num_people == 13) num_people++;
    std::cout << num_people * 100;

    return 0;
}