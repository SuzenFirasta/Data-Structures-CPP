#include<iostream>

using namespace std;

int factorial(int n){
	
	if(n<=1)
	{
		return 1;
	}
	
	int smallOutput = n * factorial(n-1);
	
	return smallOutput;
	
}

int main()
{
	
	int n;
	cout<<"Enter a number to finds its factorial :- ";
	cin>>n;
	cout<<endl;
	
	int result = factorial(n);
	
	cout<<endl;
	
	cout<<"Factorial for "<<n<<" is :- "<<result<<endl;
	
	return 0;
}
