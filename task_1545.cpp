#include <iostream>
#include <map>
#include <set>

int main() {
    size_t num_hieroglyphs;
    std::cin >> num_hieroglyphs;
    std::cin.ignore(1, '\n'); // go to next line to read chars

    std::map<char, std::set<char>> suggestions;
    char current_letter1, current_letter2;
    for(size_t i = 0; i < num_hieroglyphs; i++) {
        std::cin >> current_letter1 >> current_letter2;
        std::cin.ignore(1, '\n'); // go to next line
        suggestions[current_letter1].insert(current_letter2);
    }

    char given_letter;
    std::cin >> given_letter;
    if(suggestions.count(given_letter) > 0) {
        for (const auto& suggested_letter:suggestions.at(given_letter)) {
            std::cout << given_letter << suggested_letter << std::endl;
        }
    } // else print nothing

    return 0;
}
