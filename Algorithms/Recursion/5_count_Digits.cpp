#include <iostream>
using namespace std;

// Function to count the number of digits using recursion
int countDigits(int n) {
    if (n == 0) {
        return 0; // Base case: no more digits left
    }
    return 1 + countDigits(n / 10); // Recursive case: remove the last digit and count
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Handle the case when the number is 0
    if (number == 0) {
        cout << "Number of digits: 1" << endl;
    } else {
        int result = countDigits(number);
        cout << "Number of digits: " << result << endl;
    }

    return 0;
}
