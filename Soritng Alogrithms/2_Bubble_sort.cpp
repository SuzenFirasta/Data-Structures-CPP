#include <iostream>

using namespace std;

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    BubbleSort(arr, size);

    cout << "Your array after bubble sort is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
