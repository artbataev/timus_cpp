#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string get_a(int n) {
    std::string result = "sin(" + std::to_string(n) + ")";
    std::reverse(result.begin(), result.end()); // using reverse to append result to string and then add ')' symbol
    std::string temp;

    for (int i = n - 1; i > 0; i--) {
        temp = "sin(" + std::to_string(i) + (i % 2 == 0 ? "+" : "-");
        result.append(temp.rbegin(), temp.rend()); // reversed
    }

    std::reverse(result.begin(), result.end());
    for (int i = 0; i < n - 1; i++)
        result += ")";

    return result;
}

std::string get_s(int n) {
    std::string result;
    for (int i = 0; i < n - 1; i++)
        result += "(";

    result += get_a(1) + "+" + std::to_string(n);

    for (int i = 2; i <= n; i++)
        result += ")" + get_a(i) + "+" + std::to_string(n - i + 1);

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << get_s(n);

    return 0;
}
