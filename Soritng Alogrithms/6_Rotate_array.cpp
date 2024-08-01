#include<iostream>

using namespace std;

void rotate(int arr[], int size, int d)
{
	for(int i=0; i<d; i++){
		int temp = arr[0];
		for(int j=0; j<size; j++)
		{
			arr[j] = arr[j+1];
			
		}
		arr[size - 1] = temp;
	}
	cout << "Your array is: ";
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
	
	int d;
	cout<<"Enter how many times you want to rotate :- ";
	cin>>d;
	
	cout<<endl;
	cout<<endl;
	
	rotate(arr, size, d);
	
	return 0;
}
