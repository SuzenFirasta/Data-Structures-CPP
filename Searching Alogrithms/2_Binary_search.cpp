#include <iostream>

using namespace std;

int BinarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high)
	{
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) 
		{
            return mid;
        } 
		else if (target > arr[mid]) 
		{
            low = mid + 1;
        } 
		else 
		{
            high = mid - 1;
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

    int position = BinarySearch(arr, size, target);
    if (position != -1) {
        cout << "Element found at index: " << position << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

