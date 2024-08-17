#include<iostream>

using namespace std;

int fib(int n) {

    if (n <= 0) {  // Handle the case when n is 0 or negative
        return 0;
    }

    if (n == 1) {  // The first Fibonacci number
        return 1;
    }

    int smallOutput1 = fib(n - 1);
    int smallOutput2 = fib(n - 2);

    return smallOutput1 + smallOutput2;
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci number: ";
    cin >> n;
    cout << endl;

    cout << "The Fibonacci number at position " << n << " is: " << fib(n) << endl;

    return 0;
}
