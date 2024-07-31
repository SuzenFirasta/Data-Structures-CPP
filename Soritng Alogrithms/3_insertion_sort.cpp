#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    InsertionSort(arr, size);

    cout << "Your array after insertion sort is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
