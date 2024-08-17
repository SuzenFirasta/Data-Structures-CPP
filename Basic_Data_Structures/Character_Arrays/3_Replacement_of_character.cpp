#include<iostream>

using namespace std;

void replaceCharacter(char input[], char c1, char c2){
	
	int counter = 0;
	for(int i=0; input[i] != '\0' ; i++){
		if(input[i] == c1)
		{
			input[counter] = c2;
		}
		counter++;
	}
	
}

int main()
{
	
	char input[100];
	cout<<"Enter a string :- ";
	cin>>input;
	cout<<"Your string is :- "<<input;
	cout<<endl;	
	
	cout<<endl;
	char c1;
	cout<<"Enter a character from string :- ";
	cin>>c1;
	cout<<endl;
	
	cout<<endl;
	char c2;
	cout<<"Enter another character that you want to replace it in your string :- ";
	cin>>c2;
	cout<<endl;
	
	replaceCharacter(input, c1, c2);
	
	cout<<"Your String after replacement of characters is :- "<<input;
	
	return 0;
}
