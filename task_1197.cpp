#include <iostream>
#include <vector>

struct Position {
    int row;
    int col;
    Position(int row_, int col_): row(row_), col(col_) {};
    bool is_correct() {
        return row >= 1 && row <= 8 && col >= 1 && col <= 8;
    }
};

Position operator+(const Position& lhs, const Position& rhs) {
    return {lhs.row + rhs.row, lhs.col + rhs.col};
}


const std::vector<Position> MOVES = {
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1,  2},
        {1,  -2},
        {-1, 2},
        {-1, -2},
};


bool can_attack(Position current_position, Position offset) {
    Position new_position = current_position + offset;
    return new_position.is_correct();
}


int main() {
    int n;
    std::cin >> n;

    char col_char;
    Position current_position {0, 0};
    for (int i = 0; i < n; i++) {
        std::cin >> col_char >> current_position.row;
        current_position.col = col_char - 'a' + 1;
        int num_attacked = 0;
        for (auto offset:MOVES) {
            num_attacked += can_attack(current_position, offset);
        }
        std::cout << num_attacked << std::endl;
    }

    return 0;
}