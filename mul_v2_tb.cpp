#include <iostream>
#include <cmath>
#include <iomanip>
#include "mul_accel.h"

using namespace std;

// Reference software implementation
float sw_mul_accel(float a, float b, int iterations) {
    float res = 0.0f;
    for(int i = 0; i < iterations; i++) {
        res = a * b;
    }
    return res;
}

// Compare floating point values with tolerance
bool compare_float(float a, float b, float tolerance = 1e-5) {
    return fabs(a - b) < tolerance;
}

// Test case structure
struct TestCase {
    float a;
    float b;
    int iterations;
    string description;
};

int main() {
    int test_passed = 0;
    int test_failed = 0;
    
    cout << "========================================" << endl;
    cout << "  MULTIPLICATION ACCELERATOR TESTBENCH  " << endl;
    cout << "========================================" << endl << endl;
    
    // Define test cases
    TestCase tests[] = {
        {3.14159f, 2.71828f, 10000, "Standard case: pi * e"},
        {2.5f, 4.0f, 10000, "Simple integers"},
        {-5.5f, 3.2f, 10000, "Negative * Positive"},
        {-7.3f, -2.1f, 10000, "Negative * Negative"},
        {0.0f, 100.5f, 10000, "Zero multiplication"},
        {1.0f, 999.999f, 10000, "Identity multiplication"},
        {0.00001f, 0.00001f, 10000, "Very small numbers"},
        {123456.789f, 987654.321f, 10000, "Large numbers"},
        {3.14159f, 2.71828f, 1, "Single iteration"},
        {3.14159f, 2.71828f, 100, "100 iterations"},
        {3.14159f, 2.71828f, 1000, "1000 iterations"},
        {1.5f, 1.5f, 5000, "Square operation"},
        {-0.0f, 5.0f, 10000, "Negative zero"},
        {999.999f, 0.001f, 10000, "Large * Small"}
    };
    
    int num_tests = sizeof(tests) / sizeof(TestCase);
    
    // Run all test cases
    for(int i = 0; i < num_tests; i++) {
        float hw_result = 0.0f;
        float sw_result = sw_mul_accel(tests[i].a, tests[i].b, tests[i].iterations);
        
        // Call hardware function
        mul_accel(tests[i].a, tests[i].b, tests[i].iterations, &hw_result);
        
        // Compare results
        bool passed = compare_float(hw_result, sw_result);
        
        cout << "Test " << setw(2) << (i+1) << ": " << tests[i].description << endl;
        cout << "  Input: a=" << tests[i].a << ", b=" << tests[i].b 
             << ", iterations=" << tests[i].iterations << endl;
        cout << "  SW Result: " << setprecision(10) << sw_result << endl;
        cout << "  HW Result: " << setprecision(10) << hw_result << endl;
        cout << "  Status: ";
        
        if(passed) {
            cout << "PASSED ✓" << endl;
            test_passed++;
        } else {
            cout << "FAILED ✗" << endl;
            cout << "  Error: " << fabs(hw_result - sw_result) << endl;
            test_failed++;
        }
        cout << endl;
    }
    
    // Edge cases
    cout << "========================================" << endl;
    cout << "  EDGE CASE TESTS" << endl;
    cout << "========================================" << endl << endl;
    
    // Test with zero iterations
    float edge_result = 0.0f;
    mul_accel(3.14f, 2.71f, 0, &edge_result);
    cout << "Test: Zero iterations" << endl;
    cout << "  Result: " << edge_result << " (Expected: 0.0)" << endl;
    if(edge_result == 0.0f) {
        cout << "  Status: PASSED ✓" << endl;
        test_passed++;
    } else {
        cout << "  Status: FAILED ✗" << endl;
        test_failed++;
    }
    cout << endl;
    
    // Test with negative iterations
    edge_result = 999.0f; // Initialize with non-zero
    mul_accel(3.14f, 2.71f, -100, &edge_result);
    cout << "Test: Negative iterations" << endl;
    cout << "  Result: " << edge_result << " (Expected: 0.0)" << endl;
    if(edge_result == 0.0f) {
        cout << "  Status: PASSED ✓" << endl;
        test_passed++;
    } else {
        cout << "  Status: FAILED ✗" << endl;
        test_failed++;
    }
    cout << endl;
    
    // Summary
    cout << "========================================" << endl;
    cout << "  TEST SUMMARY" << endl;
    cout << "========================================" << endl;
    cout << "Total Tests: " << (test_passed + test_failed) << endl;
    cout << "Passed:      " << test_passed << endl;
    cout << "Failed:      " << test_failed << endl;
    cout << "Success Rate: " << fixed << setprecision(1) 
         << (100.0 * test_passed / (test_passed + test_failed)) << "%" << endl;
    cout << "========================================" << endl;
    
    if(test_failed == 0) {
        cout << "\n✓ All tests passed successfully!" << endl;
        return 0;
    } else {
        cout << "\n✗ Some tests failed!" << endl;
        return 1;
    }
}
