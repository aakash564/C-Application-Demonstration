#include <iostream>
#include <vector>

/**
 * C++ Source file for WebAssembly compilation.
 * This function calculates the Nth Fibonacci number iteratively.
 */
long long fibonacci(int n) {
    if (n < 0) return 0;
    if (n <= 1)
        return n;
    
    // Calculate Fibonacci up to N=10
    long long a = 0;
    long long b = 1;
    long long c;
    
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Emscripten automatically calls the standard main function when the module loads.
int main() {
    // std::cout output is typically redirected to a JS function (like 'print') 
    // when compiled with Emscripten, which then updates the HTML DOM.
    
    std::cout << "C++ WebAssembly Application Running (Compiled from main.cpp)" << std::endl;
    
    const int N = 10;
    std::cout << "Calculating Fibonacci(" << N << ")..." << std::endl;
    
    long long result = fibonacci(N); // Result is 55
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
