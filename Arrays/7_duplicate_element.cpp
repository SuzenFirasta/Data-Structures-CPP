#include <iostream>

using namespace std;

int duplicateNumber(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int arr[size];
    
    for (int i = 0; i < size; i++) {
    	cout << "Enter elements of the array: ";
        cin >> arr[i];
    }
    
    cout<<endl;
    
    cout << "Your array is: ";
    for (int i = 0; i < size; i++) 
	{
        cout << arr[i] << " ";
    }
    
    cout<<endl;

    int duplicate = duplicateNumber(arr, size);

    if (duplicate != -1) {
        cout << "The duplicate element in the array is: " << duplicate << endl;
    } else {
        cout << "No duplicate element found in the array." << endl;
    }

    return 0;
}
