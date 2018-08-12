#include <iostream>
#include <set>
#include <array>
#include <algorithm>

const int NUM_PLAYERS = 3;

int main() {
    std::array<std::set<int>, NUM_PLAYERS> player_values;
    std::set<int> eigenvalues{};

    int n;
    int value;
    for (int i_player = 0; i_player < NUM_PLAYERS; i_player++) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> value;
            player_values[i_player].insert(value);
        }
    }

    eigenvalues = player_values[0];
    std::set<int> temp_eigenvalues{};
    for (int i_player = 1; i_player < NUM_PLAYERS; i_player++) { // i_player = 1 because player 0 is used!
        std::set_intersection(
                eigenvalues.begin(), eigenvalues.end(),
                player_values[i_player].begin(), player_values[i_player].end(),
                std::inserter(temp_eigenvalues, temp_eigenvalues.begin())
        );
        eigenvalues = temp_eigenvalues;
        temp_eigenvalues = {};
    }

    std::cout << eigenvalues.size();
    return 0;
}