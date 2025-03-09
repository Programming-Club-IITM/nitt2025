#include <iostream>
#include <cmath>

struct Point {
  int x;
  int y;
};

template <typename T>
T add(T a, T b) {
return a + b;
}

template <typename T>
T subtract(T a, T b) {
return a - b;
}

template <typename T>
T multiply(T a, T b) {
return a * b;
}

template <typename T>
T divide(T a, T b) {
return b != 0 ? a / b : 0;
}

int get_squared_distance(Point p1, Point p2) {
return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int get_manhattan_distance(Point p1, Point p2) {
return std::abs(p2.x - p1.x) + std::abs(p2.y - p1.y);
}

bool check_same_line(Point p1, Point p2, Point p3) {
 return (p3.y - p1.y) * (p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
  int a_i = 5, b_i = 3;
float a_f = 2.5, b_f = 1.2;

std::cout << "Using default values: " << a_i << ", " << b_i << ", " << a_f << ", " << b_f << std::endl;

std::cout << "Addition of integers: " << add(a_i, b_i) << std::endl;
std::cout << "Addition of floats: " << add(a_f, b_f) << std::endl;
std::cout << "Subtraction of integers: " << subtract(a_i, b_i) << std::endl;
std::cout << "Subtraction of floats: " << subtract(a_f, b_f) << std::endl;
std::cout << "Multiplication of integers: " << multiply(a_i, b_i) << std::endl;
std::cout << "Multiplication of floats: " << multiply(a_f, b_f) << std::endl;
std::cout << "Integer division: " << divide(a_i, b_i) << std::endl;
std::cout << "Floating-point division: " << divide(a_f, b_f) << std::endl;

Point p1 = {0, 0},
p2 = {1, 1},
p3 = {2, 2};

 std::cout << "The squared distance between the points is " << get_squared_distance(p1, p2) << std::endl;
std::cout << "The Manhattan distance between the points is " << get_manhattan_distance(p1, p2) << std::endl;
std::cout << "The points lie on the same line: " << (check_same_line(p1, p2, p3) ? "true" : "false") << std::endl;

return 0;
}
