#include <iostream>
using namespace std;

int pairSum(int arr[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == x) {
                count++;
            }
        }
    }
    return count;
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
    
    
    int x;
    cout << "Enter the target sum X: ";
    cin >> x;
	
	cout<<endl;
	
    int result = pairSum(arr, size, x);
    cout << "The number of pairs with sum " << x << " is: " << result << endl;

    return 0;
}
