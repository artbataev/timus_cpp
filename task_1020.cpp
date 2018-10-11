#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define M_PI    3.14159265358979323846264338327950288

struct Point {
    double x;
    double y;
};

double compute_distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    double radius_of_nail;
    std::cin >> n >> radius_of_nail;

    std::vector<Point> points;
    points.reserve(static_cast<size_t>(n));

    double x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        points.emplace_back(Point{x, y});
    }

    double rope_length = 0.0;

    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            rope_length += compute_distance(points[i], points[i + 1]);
        }
        rope_length += compute_distance(points.front(), points.back());
    }

    rope_length += M_PI * 2 * radius_of_nail;

    std::cout << std::fixed << std::setprecision(2) << rope_length;
    return 0;
}
