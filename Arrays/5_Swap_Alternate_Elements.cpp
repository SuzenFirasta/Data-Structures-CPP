#include <iostream>

using namespace std;

// Function to swap every pair of alternate elements in the array
void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
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
	
	cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout<<endl;
	
    swapAlternate(arr, size);

    cout << "Array after swapping alternate elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
