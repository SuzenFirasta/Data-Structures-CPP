#include<iostream>

using namespace std;

void trimSpace(char input[])
{
	int j=0;
	for(int i=0; input[i] != '\0' ; i++){
		if(input[i] != ' '){
			input[j] = input[i];
			j++;
		}
	}
	
	input[j] = '\0';
	
}

int main()
{
	char input[100];
	cout<<"Enter a string :- ";
	cin.getline(input,100);
	cout<<"Your string is :- "<<input;
	cout<<endl;
	cout<<endl;
	
	trimSpace(input);
	
	cout << "String after removing spaces: " << input << endl;

	return 0;
}
