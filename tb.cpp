// ============================================================================
// exp_calc_tb.cpp - Testbench for Exponential Calculation
// Target: PYNQ-Z2 (Zynq-7020)
// ============================================================================

#include "exp_calc.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Test values covering different ranges
    data_t test_values[] = {0.0f, 1.0f, 2.5f, 5.0f, -1.5f, -2.0f, 10.0f, 0.5f};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    int passed = 0;
    int failed = 0;
    float tolerance = 0.001f; // 0.1% tolerance
    
    cout << "======================================================================" << endl;
    cout << "EXPONENTIAL CALCULATION - HLS TESTBENCH FOR PYNQ-Z2" << endl;
    cout << "======================================================================" << endl;
    cout << fixed << setprecision(6);
    
    for (int i = 0; i < num_tests; i++) {
        data_t input = test_values[i];
        
        // Call HLS function
        data_t hls_result = exp_calc(input);
        
        // Reference calculation using standard C++ math
        data_t ref_result = exp(input);
        
        // Calculate error
        data_t error = fabs(hls_result - ref_result);
        data_t relative_error = (ref_result != 0.0f) ? (error / fabs(ref_result)) : error;
        
        // Check if test passed
        bool test_passed = (relative_error < tolerance);
        
        cout << "\n--- Test " << (i + 1) << " ---" << endl;
        cout << "Input (x):        " << input << endl;
        cout << "HLS Result:       " << hls_result << endl;
        cout << "Reference (e^x):  " << ref_result << endl;
        cout << "Absolute Error:   " << error << endl;
        cout << "Relative Error:   " << (relative_error * 100) << "%" << endl;
        cout << "Status:           " << (test_passed ? "PASSED" : "FAILED") << endl;
        
        if (test_passed) {
            passed++;
        } else {
            failed++;
        }
    }
    
    cout << "\n======================================================================" << endl;
    cout << "TEST SUMMARY" << endl;
    cout << "======================================================================" << endl;
    cout << "Total Tests:  " << num_tests << endl;
    cout << "Passed:       " << passed << endl;
    cout << "Failed:       " << failed << endl;
    cout << "Success Rate: " << (passed * 100.0 / num_tests) << "%" << endl;
    cout << "======================================================================" << endl;
    
    if (failed == 0) {
        cout << "\nALL TESTS PASSED! HLS design is ready for synthesis." << endl;
        return 0;
    } else {
        cout << "\nSOME TESTS FAILED! Please review the design." << endl;
        return 1;
    }
}