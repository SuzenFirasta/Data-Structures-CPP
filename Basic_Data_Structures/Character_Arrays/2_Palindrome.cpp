#include<iostream>

using namespace std;

bool checkPalindrome(char array[])
{
	int start = 0;
	int end = 0;
	for(int i=0; array[i] != '\0'; i++){
		end++;
	}
	end = end - 1;
	while(start < end){
		if(array[start] != array[end]){
			return false;
		}
		start++;
		end--;
	}
	
	return true;
}

int main()
{
	char array[100];
	cout<<"Enter your string to check wheather it is palindrome or not :- ";
	cin>>array;
	cout<<"Your string is :- "<<array;
	cout<<endl;
	
	if(checkPalindrome(array))
	{
		cout<<"The given String "<<array<<" is Palindrome"<<endl;
	}
	else
	{
		cout<<"The given String "<<array<<" is NOT Palindrome"<<endl;
	}
	

	return 0;
}
