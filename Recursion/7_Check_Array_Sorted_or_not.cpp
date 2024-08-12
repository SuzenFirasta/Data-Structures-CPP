#include<iostream>

using namespace std;

bool isSorted(int array[], int size)
{
    if (size == 0 || size == 1)
    {
        return true; // Base Condition
    }

    if (array[0] > array[1])
    {
        return false;  // Actual condition that is checking
    }

    bool isSmallerSorted = isSorted(array + 1, size - 1);

    return isSmallerSorted;
}

int main()
{
    int size;
    cout << "Enter the length of your array: ";
    cin >> size;
    cout << endl;

    int* array = new int[size]; // Dynamic memory allocation for the array

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at position " << i << ": ";
        cin >> array[i];
    }

    cout << endl;

    cout << "Elements of your array are: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Element at position " << i << " is: " << array[i] << endl;
    }

    cout << endl;

    if (isSorted(array, size))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    delete[] array; // Freeing the dynamically allocated memory

    return 0;
}
