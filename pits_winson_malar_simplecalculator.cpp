#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

// Function to add two objects
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Function to subtract two objects
template <typename T>
T subtract(T a, T b) {
    return a - b;
}

// Function to multiply two objects
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Function to divide two integers (return integer)
template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        std::cerr << "Division by zero is not allowed!" << std::endl;
        return 0;
    }
    return a / b;
}

int get_squared_distance(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return (dx * dx) + (dy * dy);
}

int get_manhattan_distance(Point p1, Point p2) {
    // Manhattan distance is |x2-x1| + |y2-y1|
    // Use abs(x) to get |x|
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

bool check_same_line(Point p1, Point p2, Point p3) {
    //(y2-y1)/(x2-x1) is same as (y3-y1)/(x3-x1)
    //(y3-y1)*(x2-x1) == (y2-y1)*(x3-x1)
    return (p3.y - p1.y) * (p2.x - p1.x) == (p2.y - p1.y) * (p3.x - p1.x);
}
int main() {
    // Testing the functions
    /* DO NOT CHANGE ANYTHING BELOW THIS LINE*/
    int a_i, b_i;
    float a_f, b_f;

    std::cin >> a_i >> b_i >> a_f >> b_f;

    std::cout << "Addition of integers: " << add(a_i, b_i) << std::endl;
    std::cout << "Addition of floating-point numbers: " << add(a_f, b_f) << std::endl;
    std::cout << "subtraction of integers: " << subtract(a_i, b_i) << std::endl;
    std::cout << "subtraction of floating-point numbers: " << subtract(a_f, b_f) << std::endl;
    std::cout << "multiplication of integers: " << multiply(a_i, b_i) << std::endl;
    std::cout << "multiplication of floating-point numbers: " << multiply(a_f, b_f) << std::endl;
    std::cout << "Integer division: " << divide(a_i, b_i) << std::endl;
    std::cout << "Floating-point division: " << divide(a_f, b_f) << std::endl;
  
  	Point p1;
  	std::cin >> p1.x >> p1.y;
  	Point p2;
  	std::cin >> p2.x >> p2.y;
  	Point p3;
  	std::cin >> p3.x >> p3.y;
  	
  	std::cout << "The squared distance between the points is " << get_squared_distance(p1, p2) << std::endl;
  	std::cout << "The manhattan distance between the points is " << get_manhattan_distance(p1, p2) << std::endl;
  	std::cout << "The lines lies on the same line: " << check_same_line(p1, p2, p3) << std::endl;
  
  	

    return 0;
}
