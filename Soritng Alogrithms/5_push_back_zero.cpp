#include<iostream>

using namespace std;

void pushZeroBack(int arr[], int size)
{
	int count = 0;
	for(int i=0; i<size; i++){
		if(arr[i] != 0){
			int temp = arr[i];
			arr[i] = arr[count];
			arr[count] = temp;
			
			count++;
		}
	}
	
	cout<<endl;
    cout << "Your array after pushing zero back is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
	
}


int main()
{
	int size;
    cout << "Enter size of the array: ";
    cin >>size;

    int arr[size];
    for (int i = 0; i < size; i++) {
    	cout << "Enter elements of the array: ";
        cin >> arr[i];
    }
	cout<<endl;
    cout << "Your array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	cout << endl;
	
	pushZeroBack(arr, size);
	
	return 0;
}
