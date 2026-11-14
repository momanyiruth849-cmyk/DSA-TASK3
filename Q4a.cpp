#include <iostream>
using namespace std;
// (a) sum of first N natural numbers [5]

    int sum(int n){
        if (n == 0) return 0;
        return n + sum(n - 1);
    }
    
// (b) factorial of a number [5]
    int factorial(int n){
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }

// (c) nth term of the Fibonacci series [5]
    int fibonacci(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
//(d) generate n terms of the fibonacci series [5]
    void generateFibonacci(int n){
        for (int i = 0; i < n; i++){
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

int main() {
    int n = 7;
   

    cout << "Sum of first " << n << " natural numbers: " << sum(n) << endl;
    cout << "Factorial of " << n << ": " << factorial(n) << endl;
    cout << n << "th term of the Fibonacci series: " << fibonacci(n) << endl;
    cout << "First " << n << " terms of the Fibonacci series: ";
    generateFibonacci(n);

    return 0;
}