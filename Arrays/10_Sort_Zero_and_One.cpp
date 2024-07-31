#include <iostream>
using namespace std;

void sortZeroesAndOne(int input[], int size) {
    int nextZeroIndex = 0;
	//catching only zero and swapping it with first occurance of one from the start
    for (int i = 0; i < size; i++) {
        if (input[i] == 0) {
            // Swapping
            int temp = input[i];
            input[i] = input[nextZeroIndex];
            input[nextZeroIndex] = temp;
            nextZeroIndex++;
        }
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
    cout << "Your array is: ";
    for (int i = 0; i < size; i++) 
	{
        cout << arr[i] << " ";
    }
    
	cout<<endl;
    sortZeroesAndOne(arr, size);

    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
