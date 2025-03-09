#include <iostream>
#include <cmath>

int add_int(int a, int b) {
    return a + b;
}

float add_float(float a, float b) {
    return a + b;
}

int sub_int(int a, int b) {
    return a - b;
}

float sub_float(float a, float b) {
    return a - b;
}

int mul_int(int a, int b) {
    return a * b;
}

float mul_float(float a, float b) {
    return a * b;
}

int int_div_int(int a, int b) {
    return (b != 0) ? a / b : 0; // Prevent division by zero
}

float float_div_int(int a, int b) {
    return (b != 0) ? static_cast<float>(a) / b : 0;
}

float float_div_float(float a, float b) {
    return (b != 0) ? a / b : 0;
}

int power_int(int a, int b) {
    if (b < 0) return 0; // Avoids negative exponent issues
    if (b > 10) return -1; // Prevents very large calculations
    return static_cast<int>(std::pow(a, b));
}

int num_factors(int a) {
    if (a <= 0) return 0; // Prevents invalid inputs
    int count = 0;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0)
            count++;
    }
    return count;
}

int main() {
    // Predefined values (No user input)
    int a_i = 12, b_i = 4, num = 10;
    float a_f = 5.5, b_f = 2.5;

    std::cout << "Addition of integers: " << add_int(a_i, b_i) << std::endl;
    std::cout << "Addition of floating-point numbers: " << add_float(a_f, b_f) << std::endl;
    std::cout << "Subtraction of integers: " << sub_int(a_i, b_i) << std::endl;
    std::cout << "Subtraction of floating-point numbers: " << sub_float(a_f, b_f) << std::endl;
    std::cout << "Multiplication of integers: " << mul_int(a_i, b_i) << std::endl;
    std::cout << "Multiplication of floating-point numbers: " << mul_float(a_f, b_f) << std::endl;
    std::cout << "Integer division: " << int_div_int(a_i, b_i) << std::endl;
    std::cout << "Floating-point division: " << float_div_int(a_i, b_i) << std::endl;
    std::cout << "Floating-point division: " << float_div_float(a_f, b_f) << std::endl;
    std::cout << "Power: " << power_int(a_i, b_i) << std::endl;
    std::cout << "Number of factors: " << num_factors(num) << std::endl;

    return 0;
}
