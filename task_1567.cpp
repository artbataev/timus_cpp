#include <iostream>
#include <string>
#include <vector>
#include <map>

const std::vector<std::string> KEYBOARD = {
        "1", "abc",
        "2", "def",
        "3", "ghi",
        "4", "jkl",
        "5", "mno",
        "6", "pqr",
        "7", "stu",
        "8", "vwx",
        "9", "yz",
        "0", ".,!",
        "#", " ",
};

int main() {
    std::map<char, int> char2taps;
    for(const auto & keyboard_chars: KEYBOARD) {
        for(int i = 0; i < keyboard_chars.size(); i++) {
            char2taps[keyboard_chars[i]] = i + 1;
        }
    }


    std::string slogan;
    std::getline(std::cin, slogan);
    int num_taps = 0;
    for(const auto& c: slogan) {
        num_taps += char2taps[c];
    }

    std::cout << num_taps;
    return 0;
}