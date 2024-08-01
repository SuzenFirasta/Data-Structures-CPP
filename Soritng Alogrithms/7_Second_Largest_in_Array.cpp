#include<iostream>

using namespace std;

int SecondLargest(int arr[], int size){
	if (size < 2) {
        // If there are fewer than two elements, there is no second largest
        return -1; // Indicating that a second largest doesn't exist
    }

    // Initialize the largest and second largest variables
    int firstLargest = -1;
    int secondLargest = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] > firstLargest) {
            // If the current element is greater than the largest
            secondLargest = firstLargest; // Update second largest
            firstLargest = arr[i];        // Update first largest
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            // If the current element is greater than second largest and not equal to the largest
            secondLargest = arr[i]; // Update second largest
        }
    }

    return secondLargest; // Return the second largest element
	
}

int main()
{
	int size;
	cout<<"Enter size :- ";
	cin>>size;
	cout<<endl;
	
	int array[size];
	
	for(int i=0; i<size;i++)
	{
		cout<<"Enter element inside your array :- ";
		cin>>array[i];
	}
	
	cout<<endl;
	
	cout<<"Element inside your array is :- "<<endl;
	for(int i=0; i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
	cout<<endl;

	cout<<"Second Largest element in the Array is :- "<<SecondLargest(array, size);
	
	return 0;
}
