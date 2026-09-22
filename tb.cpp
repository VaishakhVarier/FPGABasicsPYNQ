#include <iostream>
#include <cmath>
#include "div_accel.h"

#define TOLERANCE 0.0001f

bool compare_float(float a, float b, float tolerance = TOLERANCE) {
    return std::abs(a - b) < tolerance;
}

int main() {
    int num_tests = 0;
    int passed_tests = 0;
    
    std::cout << "Starting Division Accelerator Testbench\n";
    std::cout << "========================================\n\n";
    
    // Test 1: Basic division
    {
        num_tests++;
        float result;
        float a = 10.0f;
        float b = 2.0f;
        int iterations = 1;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 1 PASSED: " << a << " / " << b << " = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 1 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 2: Multiple iterations (result should be same)
    {
        num_tests++;
        float result;
        float a = 100.0f;
        float b = 4.0f;
        int iterations = 1000;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 2 PASSED: " << a << " / " << b << " with " << iterations 
                      << " iterations = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 2 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 3: Floating point division
    {
        num_tests++;
        float result;
        float a = 7.5f;
        float b = 2.5f;
        int iterations = 1;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 3 PASSED: " << a << " / " << b << " = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 3 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 4: Division by zero (edge case)
    {
        num_tests++;
        float result;
        float a = 10.0f;
        float b = 0.0f;
        int iterations = 1;
        
        div_accel(a, b, iterations, &result);
        
        if (result == 0.0f) {
            std::cout << "Test 4 PASSED: Division by zero handled, result = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 4 FAILED: Division by zero not handled properly\n";
        }
    }
    
    // Test 5: Zero iterations
    {
        num_tests++;
        float result;
        float a = 10.0f;
        float b = 2.0f;
        int iterations = 0;
        
        div_accel(a, b, iterations, &result);
        
        if (result == 0.0f) {
            std::cout << "Test 5 PASSED: Zero iterations handled, result = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 5 FAILED: Zero iterations not handled properly\n";
        }
    }
    
    // Test 6: Negative iterations
    {
        num_tests++;
        float result;
        float a = 10.0f;
        float b = 2.0f;
        int iterations = -5;
        
        div_accel(a, b, iterations, &result);
        
        if (result == 0.0f) {
            std::cout << "Test 6 PASSED: Negative iterations handled, result = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 6 FAILED: Negative iterations not handled properly\n";
        }
    }
    
    // Test 7: Division with negative numbers
    {
        num_tests++;
        float result;
        float a = -20.0f;
        float b = 4.527f;
        int iterations = 1;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 7 PASSED: " << a << " / " << b << " = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 7 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 8: Division with both negative numbers
    {
        num_tests++;
        float result;
        float a = -30.0f;
        float b = -6.0f;
        int iterations = 1;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 8 PASSED: " << a << " / " << b << " = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 8 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 9: Very small divisor
    {
        num_tests++;
        float result;
        float a = 1.0f;
        float b = 0.001f;
        int iterations = 1;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected, 0.1f)) {
            std::cout << "Test 9 PASSED: " << a << " / " << b << " = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 9 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Test 10: Large iteration count
    {
        num_tests++;
        float result;
        float a = 50.0f;
        float b = 5.0f;
        int iterations = 10000;
        float expected = a / b;
        
        div_accel(a, b, iterations, &result);
        
        if (compare_float(result, expected)) {
            std::cout << "Test 10 PASSED: " << a << " / " << b << " with " << iterations 
                      << " iterations = " << result << "\n";
            passed_tests++;
        } else {
            std::cout << "Test 10 FAILED: Expected " << expected << ", got " << result << "\n";
        }
    }
    
    // Summary
    std::cout << "\n========================================\n";
    std::cout << "Test Summary: " << passed_tests << "/" << num_tests << " tests passed\n";
    
    if (passed_tests == num_tests) {
        std::cout << "All tests PASSED!\n";
        return 0;
    } else {
        std::cout << "Some tests FAILED!\n";
        return 1;
    }
}