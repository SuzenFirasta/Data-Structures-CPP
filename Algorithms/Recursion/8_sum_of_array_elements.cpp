#include<iostream>

using namespace std;

int arraySum(int array[], int size)
{
    if (size <= 0) {
        return 0;
    }

    int smallOutput = array[size - 1] + arraySum(array, size - 1);

    return smallOutput;
}

int main()
{
    int size;
    cout << "Enter the length of the array: ";
    cin >> size;
    cout << endl;

    int* array = new int[size]; // Dynamic Allocation

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at position " << i << ": ";
        cin >> array[i];
    }

    cout << endl;

    cout << "Elements of your array are: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << endl;

    cout << "The sum of the array elements is: " << arraySum(array, size) << endl;

    delete[] array; // Deallocate the dynamically allocated memory

    return 0;
}
