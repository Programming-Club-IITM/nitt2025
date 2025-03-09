#include <iostream>
#include <cmath>
using namespace std;


// Function to add two integers
int add_int(int a, int b) {
    return a + b;
}

// Function to add two floating-point numbers
float add_float(float a, float b) {
    return a + b;
}

// Function to subtract two integers
int sub_int(int a, int b) {
    return a - b;
}

// Function to subtract two floating-point numbers
float sub_float(float a, float b) {
    return a - b;
}

// Function to multiply two integers
int mul_int(int a, int b) {
    return a * b;
}

// Function to multiply two floating-point numbers
float mul_float(float a, float b) {
    return a * b;
}

// Function to divide two integers (return integer)
int int_div_int(int a, int b) {
    if (b == 0) {
        cout<< "Denominator can't be zero\n";
        return 0;
    }
    return a / b;
}

// Function to divide two integers (return floating-point)
float float_div_int(int a, int b) {
    if (b == 0) {
        cout<< "Denominator can't be zero\n";
        return 0.0;
    }
    return static_cast<float>(a) / b;
}

// Function to divide two floating-point numbers
float float_div_float(float a, float b) {
    if (b == 0) {
        cout<< "Denominator can't be zero\n";
        return 0.0;
    }
    return a / b;
}

// Function to calculate the power (a^b) for integers a and b
int power_int(int a, int b) {
    return std::pow(a, b);
}

// Function to determine the number of factors of a given number
int num_factors(int a) {
    int count = 0;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    // Testing the functions
    /* DO NOT CHANGE ANYTHING BELOW THIS LINE*/
    int a_i, b_i;
    float a_f, b_f;
    int num;

    std::cin >> a_i >> b_i >> a_f >> b_f >> num;

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

