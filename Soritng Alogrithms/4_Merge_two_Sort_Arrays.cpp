#include <iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2) {
    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and insert smaller element into mergedArray
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Insert remaining elements of arr1
    while (i < size1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    // Insert remaining elements of arr2
    while (j < size2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }

    // Print merged array
    cout << "Merged array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1;
    cout << "Enter size of the first array: ";
    cin >> size1;

    int arr1[size1];
    for (int i = 0; i < size1; i++) {
    	cout << "Enter elements of the first array: ";
        cin >> arr1[i];
    }
	cout<<endl;
    cout << "Your first array is: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << endl;

    int size2;
    cout << "Enter size of the second array: ";
    cin >> size2;

    int arr2[size2];
    for (int i = 0; i < size2; i++) {
    	cout << "Enter elements of the second array: ";
        cin >> arr2[i];
    }
	cout<<endl;
    cout << "Your second array is: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Merge the arrays
    merge(arr1, size1, arr2, size2);

    return 0;
}
