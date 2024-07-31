#include <iostream>

using namespace std;

void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swapping
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
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

    SelectionSort(arr, size);
    
    cout << "Your array after selection sort is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
