#include<iostream>
#include<cstring>

using namespace std;

void printSubStrings(char array[])
{
	int size = strlen(array);
	
	for(int start=0; start<size; start++)
	{
		for(int end=start; end<size; end++)
		{
			for(int k=start; k<=end; k++)
			{
				cout<<array[k];
			}
			cout<<endl;
		}
	}
}

int main()
{
	
	char array[100];
	cout<<"Enter you name :- ";
	cin>>array;
	cout<<"Your Name is :- "<<array;
	cout<<endl;
	
	printSubStrings(array);
	
	return 0;
}
