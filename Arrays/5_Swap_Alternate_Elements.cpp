#include <iostream>

using namespace std;

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    cout << endl;

    int arr[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    swapAlternate(arr, size);

    cout << "Array after swapping alternate elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
