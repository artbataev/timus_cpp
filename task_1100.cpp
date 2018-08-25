#include <iostream>
#include <algorithm>
#include <vector>

struct TeamSolution {
    int id;
    int solved_problems;

    TeamSolution(int id_, int solved_problems_): id(id_), solved_problems(solved_problems_) {};
};

bool operator>(const TeamSolution& lhs, const TeamSolution& rhs) {
    return lhs.solved_problems > rhs.solved_problems;
}

std::ostream& operator<<(std::ostream& stream, const TeamSolution& team_solution) {
    stream << team_solution.id << " " << team_solution.solved_problems;
    return stream;
}

int main() {
    size_t num_teams;
    std::cin >> num_teams;

    std::vector<TeamSolution> team_solutions;
    team_solutions.reserve(num_teams);
    int current_id, current_solved_problems;
    for(size_t i = 0; i < num_teams; i++) {
        std::cin >> current_id >> current_solved_problems;
        team_solutions.push_back({current_id, current_solved_problems});
    }

    std::stable_sort(team_solutions.begin(), team_solutions.end(), std::greater<>());
    for(const auto& team_solution:team_solutions) {
        std::cout << team_solution << std::endl;
    }
    return 0;
}
