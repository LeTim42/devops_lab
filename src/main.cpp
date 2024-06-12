#include "gd.hpp"
#include <iomanip>

int main() {
    std::string function;
    double left_border, right_border, step_len;
    size_t max_steps_count;
    std::cout << "Enter a function: ";
    std::getline(std::cin, function);
    std::cout << "Left border: ";
    std::cin >> left_border;
    std::cout << "Right border: ";
    std::cin >> right_border;
    std::cout << "Step length: ";
    std::cin >> step_len;
    std::cout << "Maximum steps count: ";
    std::cin >> max_steps_count;
    std::cout << std::endl;
    auto gd = gradient_descent(std::move(function), left_border, right_border, step_len, max_steps_count);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Start point: " << gd.front() << std::endl;
    std::cout << "End point: " << gd.back() << std::endl;
    std::cout << "Steps: " << gd.size() << std::endl;
    return 0;
}
