#include<iostream>
using namespace std;

int main(){
   
   int size;
   cin>>size;

   int array[size];

   for(int i=0; i<size ; i++)
   {
       cin>>array[i];
   }
   
   cout<<endl;

    int sum=0;

   for(int i=0; i<size ; i++)
   {
        sum = sum + array[i];   
   }

    cout<<sum;
    return 0;
}



