#include<iostream>

using namespace std;

int main()
{
	
	int rows;
	cout<<"Enter Number of rows :- ";
	cin>>rows;
	cout<<endl;
	
	int cols;
	cout<<"Enter Number of cols :- ";
	cin>>cols;
	cout<<endl;
	
	//creating 2D array dynamically
	
	int **arr2D = new int*[rows];
	for(int i=0; i<rows; i++)
	{
		arr2D[i] = new int[cols];
	}
	
	// Input Elements
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr2D[i][j];
        }
    }

    // Output elements
    cout << "The 2D array is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }
    
    //deleting from memory
    
    for(int i=0; i<rows ; i++)
    {
    	delete [] arr2D[i];
	}
	
	delete [] arr2D;
	
	
	return 0;
}
