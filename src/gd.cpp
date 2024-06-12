#include "gd.hpp"

std::mt19937 engine;
Function f;
size_t n;

int64_t now() {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
}

double dist(const Point& p1, const Point& p2) {
    double d = 0;
    for (size_t i = 0; i < n; ++i)
        d += sqr(p1.x[i] - p2.x[i]);
    return sqrt(d);
}

Point gradient(const Point& point) {
    Point res(n);
    Point delta(point);
    double y = f(point);
    for (size_t i = 0; i < n; ++i) {
        delta.x[i] += H;
        res.x[i] = (f(delta) - y) / H;
        delta.x[i] = point.x[i];
    }
    return res;
}

std::vector<Point> gradient_descent(std::string&& function, double left_border, double right_border, double step_len, size_t max_steps_count) {
    f = Function(std::move(function));
    n = f.get_ndim();
    std::vector<Point> points(1, Point(n));
    auto range = std::uniform_real_distribution<double>(left_border, right_border);
    for (size_t i = 0; i < n; ++i)
        points[0].x[i] = range(engine);
    if (max_steps_count == 0) return points;
    size_t step = 0;
    bool out_of_bounds = false;
    do {
        points.emplace_back(points.back() - gradient(points.back()) * step_len);
        for (double& x : points.back().x) {
            if (left_border > x || x > right_border) {
                x = std::min(std::max(x, left_border), right_border);
                out_of_bounds = true;
            }
        }
        ++step;
    } while (!out_of_bounds && dist(points[points.size()-2], points.back()) > D && step < max_steps_count);
    return points;
}
