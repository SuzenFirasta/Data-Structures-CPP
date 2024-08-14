#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    // Base case: If size is 0, x is not found, return -1
    if (size == 0) {
        return -1;
    }
    
    // Check if the first element is x
    if (input[0] == x) {
        return 0;
    }
    
    // Recursive call to check in the rest of the array
    int subIndex = firstIndex(input + 1, size - 1, x);
    
    // If x was found in the sub-array, adjust the index
    if (subIndex != -1) {
        return subIndex + 1;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to find: ";
    cin >> x;

    int index = firstIndex(arr, n, x);
    if (index != -1) {
        cout << "First index of " << x << " is: " << index << endl;
    } else {
        cout << x << " is not present in the array." << endl;
    }

    // Clean up the allocated memory
    delete[] arr;

    return 0;
}


/*
Sample Outputs :-

Enter the size of the array: 6
Enter the elements of the array: 1 2 3 4 5 3
Enter the element to find: 3
First index of 3 is: 2

Enter the size of the array: 5
Enter the elements of the array: 10 20 30 40 50
Enter the element to find: 25
25 is not present in the array.

*/
