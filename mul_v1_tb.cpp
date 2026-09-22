#include "mul_accel.h"
#include <iostream>

int main() {

    float a = 5.0;
    float b = 6.0;
    float result;

    // Call the HLS function
    mul_accel(a, b, &result);

    // Display result
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "Result = " << result << std::endl;

    // Check result
    if (result == 30.0) {
        std::cout << "TEST PASSED" << std::endl;
        return 0;
    } else {
        std::cout << "TEST FAILED" << std::endl;
        return 1;
    }
}
