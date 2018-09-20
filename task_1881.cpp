#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);

    int num_lines_on_page, num_symbols_in_line, num_words;
    std::cin >> num_lines_on_page >> num_symbols_in_line >> num_words;

    int total_lines = 0;
    int used_symbols_in_current_line = 0;
    std::string word;
    for(int i = 0; i < num_words; i++) {
        std::cin >> word;
        int word_len = static_cast<int>(word.length());
        if (used_symbols_in_current_line == 0) {
            total_lines++;
            used_symbols_in_current_line += word_len;
        } else if (used_symbols_in_current_line + 1 + word_len <= num_symbols_in_line) {
            used_symbols_in_current_line += 1 + word_len;
        } else {
            total_lines++;
            used_symbols_in_current_line = word_len;
        }
    }

    int total_pages = (total_lines + num_lines_on_page - 1) / num_lines_on_page;
    std::cout << total_pages;

    return 0;
}
