#include<iostream>

using namespace std;

void PrintArray(int array[], int size)
{
	cout<<"Element inside your array is :- "<<endl;
	for(int i=0; i<size;i++)
	{
		cout<<array[i]<<" ";
	}
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
	
	PrintArray(array, size);
	
	
	return 0;
}
