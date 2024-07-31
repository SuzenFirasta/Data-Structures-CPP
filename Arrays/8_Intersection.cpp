#include <iostream>

using namespace std;

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                // To avoid printing duplicate elements in the intersection
                bool isDuplicate = false;
                for (int k = 0; k < i; k++) {
                    if (arr1[k] == arr1[i]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    cout << arr1[i] << " ";
                }
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int size1, size2;

    cout << "Enter size of the first array: ";
    cin >> size1;
    int arr1[size1];
    for (int i = 0; i < size1; i++) {
    	cout << "Enter elements of the first array: ";
        cin >> arr1[i];
    }
    
    cout << "Your array is: ";
    for (int i = 0; i < size1; i++) 
	{
        cout << arr1[i] << " ";
    }
    
    cout<<endl;

    cout << "Enter size of the second array: ";
    cin >> size2;
    int arr2[size2];
    
    for (int i = 0; i < size2; i++) {
    	cout << "Enter elements of the second array: ";
        cin >> arr2[i];
    }
    
    cout << "Your array is: ";
    for (int i = 0; i < size2; i++) 
	{
        cout << arr2[i] << " ";
    }
    
    cout<<endl;

    cout << "The intersection of the two arrays is: ";
    findIntersection(arr1, size1, arr2, size2);

    return 0;
}
