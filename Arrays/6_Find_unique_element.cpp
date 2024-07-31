#include <iostream>

using namespace std;

int findUnique(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int uniqueElement = findUnique(arr, size);

    cout << "The unique element in the array is: " << uniqueElement << endl;

    return 0;
}
