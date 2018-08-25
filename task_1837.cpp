#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <array>

const std::string MAIN_MEMBER = "Isenbaev";

using TeamType = std::array<std::string, 3>;
using IsenbaevsNumbersType = std::map<std::string, int>;

std::istream& operator>>(std::istream& stream, TeamType& team) {
    stream >> team[0] >> team[1] >> team[2];
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const IsenbaevsNumbersType& isenbaevs_numbers) {
    for (const auto&[member, number]: isenbaevs_numbers) {
        stream << member << " ";
        if (number < 0) {
            stream << "undefined";
        } else {
            stream << number;
        }
        stream << std::endl;
    }
    return stream;
}

int main() {
    size_t num_teams;
    std::cin >> num_teams;
    std::string name1, name2, name3;

    std::map<std::string, std::set<std::string>> teammates;
    IsenbaevsNumbersType isenbaevs_numbers;
    TeamType team;
    for (size_t i = 0; i < num_teams; i++) {
        std::cin >> team;
        for (const auto& member: team) {
            isenbaevs_numbers[member] = -1;
            for (const auto& member2: team) {
                if (member != member2) {
                    teammates[member].insert(member2);
                }
            }
        }
    }

    // Breadth-first search
    std::queue<std::string> members_to_update_teammates;
    if (isenbaevs_numbers.count(MAIN_MEMBER) > 0) { // if Isenbaev was in teams
        isenbaevs_numbers[MAIN_MEMBER] = 0;
        members_to_update_teammates.push(MAIN_MEMBER);
    }
    while(!members_to_update_teammates.empty()) {
        std::string current_member = members_to_update_teammates.front();
        members_to_update_teammates.pop();
        if(teammates.count(current_member) > 0) {
            for (const auto& teammate: teammates.at(current_member)) {
                if (isenbaevs_numbers[teammate] < 0) {
                    isenbaevs_numbers[teammate] = isenbaevs_numbers[current_member] + 1;
                    members_to_update_teammates.push(teammate);
                }
            }
        }
    }

    std::cout << isenbaevs_numbers;

    return 0;
}
