#include<iostream>

using namespace std;

// Finding Largest element in the array

int main()
{
	int size;
	cout<<"Enter the length of an array :- ";
	cin>>size;
	cout<<endl;
	
	int array[size];
	
	for(int i=0;  i<size ;i++)
	{
		cout<<"Enter the element inside your array :- ";
		cin>>array[i];
	}
	cout<<endl;
	cout<<"Elements inside your array are :- "<<endl;
	for(int i=0; i<size ;i++)
	{
		cout<<"Element at position "<<i<<" is :- "<<array[i]<<endl;
	}
	
	cout<<endl;
	
	int max = array[0];
	
	for(int i=0;i<size;i++)
	{
		if(array[i]>max)
		{
			max = array[i];
		}
	}
	
	cout<<"Largest element of you array is :- "<<max<<endl;
	
	return 0;
}
