#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
    // Base case: If size is 0, x is not found, return -1
    if (size == 0) {
        return -1;
    }
    
    // Check the last element first
    if (input[size - 1] == x) {
        return size - 1;
    }
    
    // Recursive call to check in the rest of the array
    return lastIndex(input, size - 1, x);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout<<endl;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at position " << i << ": ";
        cin >> arr[i];
    }
	cout<<endl;
	
    int x;
    cout << "Enter the element to find: ";
    cin >> x;
    cout<<endl;

    int index = lastIndex(arr, n, x);
    if (index != -1) {
        cout << "Last index of " << x << " is: " << index << endl;
    } else {
        cout << x << " is not present in the array." << endl;
    }

    // Clean up the allocated memory
    delete[] arr;

    return 0;
}

/*
Sample Outputs :- 
  
Enter the size of the array: 6
Enter the elements of the array: 1 2 3 4 5 3
Enter the element to find: 3
Last index of 3 is: 5

Enter the size of the array: 5
Enter the elements of the array: 10 20 30 40 50
Enter the element to find: 25
25 is not present in the array.

*/
