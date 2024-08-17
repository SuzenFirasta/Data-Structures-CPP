#include<iostream>

using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of your array :- ";
	cin>>size;
	cout<<endl;
	
	int *arr = new int[size];
	
	for(int i=0; i<size; i++)
	{
		cout<<"Enter an element inside your array :- ";
		cin>>arr[i];
	}
	
	cout<<endl;
	
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	
	delete [] arr;
	
	return 0;
}
