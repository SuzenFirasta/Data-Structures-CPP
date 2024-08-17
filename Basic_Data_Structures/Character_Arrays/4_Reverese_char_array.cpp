#include<iostream>

using namespace std;

void reverse(char array[])
{
	int start = 0;
	int end = 0;
	
	for(int i=0; array[i] != '\0'; i++){
		end++;
	}
	end = end - 1;
	
	char temp;
	
	while(start < end){
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		
		start++;
		end--;
	}
	
	cout<<"Your Reversed character array is :- "<<array;
}

int main(){
	
	char input[100];
	cout<<"Enter a string :- ";
	cin.getline(input,100);
	cout<<"Your string is :- "<<input;
	cout<<endl;
	cout<<endl;
	
	reverse(input);
	
	
	return 0;
}
