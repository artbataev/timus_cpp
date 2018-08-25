#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <array>

static const std::string MAIN_MEMBER = "Isenbaev";

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

template<typename Key>
std::map<Key, int> compute_distance(const std::map<Key, std::set<Key>>& graph, const Key& root) {
    // Breadth-first search
    std::map<Key, int> distances;
    std::queue<Key> elements_to_update_neighbours;
    for (const auto&[element, _]: graph) {
        distances[element] = -1;
    }
    if (graph.count(root) > 0) { // if Isenbaev was in teams
        distances[MAIN_MEMBER] = 0;
        elements_to_update_neighbours.push(MAIN_MEMBER);
    }
    while (!elements_to_update_neighbours.empty()) {
        std::string current_element = elements_to_update_neighbours.front();
        elements_to_update_neighbours.pop();
        if (graph.count(current_element) > 0) {
            for (const auto& teammate: graph.at(current_element)) {
                if (distances[teammate] < 0) {
                    distances[teammate] = distances[current_element] + 1;
                    elements_to_update_neighbours.push(teammate);
                }
            }
        }
    }
    return distances;
}

int main() {
    size_t num_teams;
    std::cin >> num_teams;
    std::string name1, name2, name3;

    std::map<std::string, std::set<std::string>> teammates;
    TeamType team;
    for (size_t i = 0; i < num_teams; i++) {
        std::cin >> team;
        for (const auto& member: team) {
            for (const auto& member2: team) {
                if (member != member2) {
                    teammates[member].insert(member2);
                }
            }
        }
    }

    IsenbaevsNumbersType isenbaevs_numbers = compute_distance(teammates, MAIN_MEMBER);
    std::cout << isenbaevs_numbers;

    return 0;
}
