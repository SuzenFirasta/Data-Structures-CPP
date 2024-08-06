## Sorting

Sorting means an arrangement of elements in an ordered sequence either in increasing(ascending) order or decreasing(descending) order. Sorting is very important, and many software and programs use this. Binary search also requires sorting. There are many different sorting techniques. The major difference is the amount of space and time they consume while being performed in the program.

For now, we will be discussing the following sorting techniques only:

- Selection sort
- Bubble sort
- Insertion sort

Let’s discuss them one-by-one…

### Selection Sort:

**Steps: (sorting in increasing order)**

1. First-of-all, we will find the smallest element of the array and swap that with the element at index 0.
2. Similarly, we will find the second smallest and swap that with the element at index 1 and so on…
3. Ultimately, we will be getting a sorted array in increasing order only.

Let us look at the example for a better understanding:

Consider the following depicted array as an example. You want to sort this array in increasing order.

### Implementation of Selection Sort

```cpp
#include <iostream>
using namespace std;

void selectionSort(int input[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find min element in the array
        int min = input[i], minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (input[j] < min) {
                min = input[j];
                minIndex = j;
            }
        }
        // Swap
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}

int main() {
    int input[] = {3, 1, 6, 9, 0, 4};
    selectionSort(input, 6);
    for (int i = 0; i < 6; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}
```

### Bubble Sort:

In selection sort, the elements from the start get placed at the correct position first and then the further elements, but in the bubble sort, the elements start to place correctly from the end.

In this technique, we just compare the two adjacent elements of the array and then sort them manually by swapping if not sorted. Similarly, we will compare the next two elements (one from the previous position and the corresponding next) of the array and sort them manually. This way, the elements from the last get placed in their correct position. This is the difference between selection sort and bubble sort.

### Implementation of Bubble Sort

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    // run loops two times: one for walking through the array
    // and the other for comparison
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            // To sort in descending order, change > to < in this line.
            if (array[i] > array[i + 1]) {
                // swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// function to print the

 array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << endl;
}

// driver code
int main() {
    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, size);
    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}
```

### Insertion Sort:

Insertion Sort works similar to how we sort a hand of playing cards.

Imagine that you are playing a card game. You're holding the cards in your hand, and these cards are sorted. The dealer hands you exactly one new card. You have to put it into the correct place so that the cards you're holding are still sorted. In selection sort, each element that you add to the sorted subarray is no smaller than the elements already in the sorted subarray. But in our card example, the new card could be smaller than some of the cards you're already holding, and so you go down the line, comparing the new card against each card in your hand until you find the place to put it. You insert the new card in the right place, and once again, your hand holds fully sorted cards. Then the dealer gives you another card, and you repeat the same procedure. Then another card, and another card, and so on, until the dealer stops giving you cards. This is the idea behind insertion sort.

Loop over positions in the array, starting with index 1. Each new position is like the new card handed to you by the dealer, and you need to insert it into the correct place in the sorted subarray to the left of that position.

Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.

### Implementation of Insertion Sort

```cpp
#include <iostream>
using namespace std;

void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void insertionSort(int array[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i]; // take value
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key; // insert in right place
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n]; // create an array with given number of elements
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before Sorting: ";
    display(arr, n);

    insertionSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
}
```

Now, practice different questions to get more familiar with the concepts. In the advanced course, you will study more types of sorting techniques.

### Practice

- **For binary search:** [Binary Search Practice Problems](https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/)

- **For sorting:** [Bubble Sort Tutorial](https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/tutorial/)

  (In this link, you will find the questions for bubble sort, check out the left tab, from there you can switch to other sorting techniques.)
```
