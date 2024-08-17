#include <iostream>
using namespace std;

// Function to calculate power using recursion
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Base case: any number to the power of 0 is 1
    } else {
        return base * power(base, exponent - 1); // Recursive case
    }
}

int main() {
    int base, exponent;
    cout << "Enter base number: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    
	cout<<endl;
	
    int result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}
