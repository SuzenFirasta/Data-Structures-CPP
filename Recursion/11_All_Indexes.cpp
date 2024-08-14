#include <iostream>
using namespace std;

int findAllIndexes(int input[], int size, int x, int output[]) {
    // Base case: If size is 0, return 0 as no index found
    if (size == 0) {
        return 0;
    }

    // Recursive call to find indexes in the rest of the array
    int smallOutputSize = findAllIndexes(input + 1, size - 1, x, output);

    // If the first element is equal to x, adjust indexes in output array
    if (input[0] == x) {
        for (int i = smallOutputSize - 1; i >= 0; i--) {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        return smallOutputSize + 1;
    } else {
        for (int i = 0; i < smallOutputSize; i++) {
            output[i] = output[i] + 1;
        }
        return smallOutputSize;
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

    int* output = new int[n]; // Allocate maximum size for output
    int size = findAllIndexes(arr, n, x, output);

    if (size == 0) {
        cout << x << " is not present in the array." << endl;
    } else {
        cout << "Indexes of " << x << " are: ";
        for (int i = 0; i < size; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
    }

    // Clean up the allocated memory
    delete[] arr;
    delete[] output;

    return 0;
}

*/
Sample Outputs :- 
  
Enter the size of the array: 6
Enter the elements of the array: 1 2 3 2 2 5
Enter the element to find: 2
Indexes of 2 are: 1 3 4 

Enter the size of the array: 5
Enter the elements of the array: 10 20 30 40 50
Enter the element to find: 25
25 is not present in the array.

Enter the size of the array: 8
Enter the elements of the array: 7 8 9 7 8 9 7 8
Enter the element to find: 7
Indexes of 7 are: 0 3 6
*/
