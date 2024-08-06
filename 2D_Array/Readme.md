## 2D Arrays

Combination of many 1D arrays forms a 2D array.

### Syntax to Declare a 2D Array:

```cpp
datatype array_name[rows][columns];
```

where rows imply the number of rows needed for the array and column implies the number of columns needed.

For example: If we want to declare an integer array of size 2x3, then:

```cpp
int arr[2][3];
```

It looks like:

|   | 0 | 1 | 2 |
|---|---|---|---|
| 0 |   |   |   |
| 1 |   |   |   |

In this array, you can store the values as required. Suppose in the above array you want to store 3 at every index, you can do so using the following code:

```cpp
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 3; j++)
    {
        arr[i][j] = 3;
    }
}
```

where, `arr[i][j]` invokes the element of the ith row and jth column.

### How are 2D Arrays Stored in the Memory?

They are actually stored as a 1D array of size `(number_of_rows * number_of_columns)`.

Like if you have an array of size 5 x 5, so in the memory, a 1D array is created of size 25 and if you want to get the value of the element (2,1) in this array, it will invoke `(2*5 + 1 = 11)`th position in the array. We don’t need to take care of this calculation, these are done by the compiler itself.

If we want to pass this array to a function, we can simply pass the name of the array as we did in the case of 1D arrays. But in the function definition, we can leave the first dimension empty, though the second dimension always needs to be specified.

#### Syntax for Function Call:

```cpp
int fun (int arr[][number_of_columns], int n, int m) {
    // Function code...
}
```

## Let’s Move to Some Questions Now:

### Practice Problems:

**Arrays and strings:**

- [Hackerearth Array Strings Problems](https://www.hackerearth.com/challenges/competitive/code-monk-array-strings/problems/)

**2D arrays:**

- [Hackerrank 2D Array Problem](https://www.hackerrank.com/challenges/2d-array/problem)
- [Techgig 2D Arrays Practice](https://www.techgig.com/practice/data-structure/two-dimensional-arrays)

Rest there are many questions available for practice on Codezen too. You can try them also.
```

This Markdown version should preserve the formatting and content from the original PDF document. Let me know if there's anything else you need!
