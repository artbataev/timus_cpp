#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);

    std::string source_message;
    std::cin >> source_message;

    std::string result_message;

    result_message.reserve(source_message.size());
    const int message_size = static_cast<int>(source_message.size());
    int i = 0;
    while (i < message_size) {
        if (i < message_size - 1 && source_message[i] == source_message[i + 1])
            i += 2;
        else if (result_message.empty() || result_message.back() != source_message[i]) {
            result_message += source_message[i];
            i++;
        } else { // result_message.back() == source_message[i]
            // remove last added character
            result_message.pop_back();
            i++;
        }
    }

    std::cout << result_message;

    return 0;
}
