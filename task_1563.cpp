#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::string temp;
    std::getline(std::cin, temp);
    n = std::stoi(temp);

    int said_bayan = 0;
    std::set<std::string> visited_brands;

    std::string current_brand;
    for(int i = 0; i < n; i++) {
        std::getline(std::cin, current_brand);
        std::transform(current_brand.begin(), current_brand.end(), current_brand.begin(), ::tolower);
        if(visited_brands.count(current_brand) > 0) {
            said_bayan++;
        }
        else {
            visited_brands.insert(current_brand);
        }
    }
    std::cout << said_bayan;

    return 0;
}
