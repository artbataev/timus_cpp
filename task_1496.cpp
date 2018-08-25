#include <iostream>
#include <map>
#include <string>

const int MIN_SUBMISSIONS_TO_BE_SPAMMER = 2;

int main() {
    size_t num_submissions;
    std::cin >> num_submissions;

    std::map<std::string, int> team_submissions_counter;
    std::string current_team;
    for(size_t i = 0; i < num_submissions; i++) {
        std::cin >> current_team;
        team_submissions_counter[current_team]++;
    }

    for(const auto&[team, team_submissions_count]: team_submissions_counter) {
        if (team_submissions_count >= MIN_SUBMISSIONS_TO_BE_SPAMMER) {
            std::cout << team << std::endl;
        }
    }

    return 0;
}
