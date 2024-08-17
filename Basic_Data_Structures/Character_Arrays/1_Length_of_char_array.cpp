#include<iostream>

using namespace std;

int length(char array[]){
	int count = 0;
	for(int i=0; array[i] != '\0'; i++){
		count++;
	}
	return count;
}

int main()
{
	char array[100];
	cout<<"Enter you name :- ";
	cin>>array;
	cout<<"Your Name is :- "<<array;
	cout<<endl;
	cout<<"Length of your name is :- "<<length(array);
	return 0;
}
