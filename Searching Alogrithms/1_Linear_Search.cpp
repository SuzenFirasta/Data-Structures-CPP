
#include <iostream>

using namespace std;

int LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter size of your array: ";
    cin >> size;
    cout << endl;
    
    int arr[size];
    
    // Entering elements inside the array
    for (int i = 0; i < size; i++) {
        cout << "Enter an element inside your array: ";
        cin >> arr[i];
    }
    
    cout << endl;
    
    cout << "Your array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    int target;
    cout << "Enter a number to find its position: ";
    cin >> target;
    
    int position = LinearSearch(arr, size, target);
    if (position != -1) {
        cout << "Element found at index: " << position << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    
    return 0;
}
