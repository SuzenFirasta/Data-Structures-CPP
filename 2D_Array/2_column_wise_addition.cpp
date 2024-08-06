#include<iostream>

using namespace std;


int main()
{
	int rows;
	cout<<"Enter Number of rows :- ";
	cin>>rows;
		
	int cols;
	cout<<"Enter Number of columns :- ";
	cin>>cols;
	
	cout<<endl;
	
	int a[rows][cols];
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<"Enter an element at "<<i<<" row and "<<j<<" column :- ";
			cin>>a[i][j];
		}
	}
	cout<<endl;
	cout<<"Your 2D array is :- "<<endl;
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for (int j = 0; j < cols; j++)
    {
        int sum = 0; // Reset sum for each column
        for (int i = 0; i < rows; i++)
        {
            sum = sum + a[i][j];
        }

        cout << "Sum of column " << j << " is: " << sum << endl;
    }
    
	return 0;
}
