## Pointers

### Address of Operator (&)

The address of a variable can be obtained by preceding the name of a variable with an ampersand sign (&), known as the address-of operator. For example:

```cpp
cout << (&var) << endl;
```

This would print the address of the variable `var`; by preceding the name of the variable `var` with the address-of operator (&), we are no longer printing the content of the variable itself, but its address.

### What are Pointers?

Pointers are one of the most important aspects of C++. Pointers are another type of variables in C++ and these variables store addresses of other variables.

While creating a pointer variable, we need to mention the type of data whose address is stored in the pointer. For example, to create a pointer that stores the address of an integer, we need to write:

```cpp
int* p;
```

This means that `p` will contain the address of an integer. So, if a pointer is going to store the address of datatype `X`, it will be declared like this:

```cpp
X* p;
```

Now let’s say we have an integer `i` and an integer pointer `p`, we will use the address-of (&) operator to put the address of `i` in `p`. The address-of operator `&` is a unary operator that returns the address of a variable. For example, `&i` will give us the address of variable `i`. Here is the code to put the address of `i` in `p`.

```cpp
int i = 10;
int* p;
p = &i;
```

### Dereference Operator (*)

As just seen, a variable which stores the address of another variable is called a pointer. Pointers are said to "point to" the variable whose address they store.

An interesting property of pointers is that they can be used to access the variable they point to directly. This is done by preceding the pointer name with the dereference operator (*). The operator itself can be read as "value pointed to by."

Therefore, following the values of the previous example, consider the following statement:

```cpp
int a = *p;
```

So in this assignment, we are assigning the value pointed to by pointer `p` (i.e., the value of `i`) to the integer variable `a`.

The reference and dereference operators are thus complementary:

- `&` is the address-of operator, and can be read simply as "address of"
- `*` is the dereference operator, and can be read as "value pointed to by"

Thus, they have sort of opposite meanings: An address obtained with `&` can be dereferenced with `*`.

Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), and should not be confused with the dereference operator seen above, but which is also written with an asterisk (*). They are simply two different things represented with the same sign.

```cpp
#include <iostream>
using namespace std;

int main() {
    int firstvalue = 5, secondvalue = 15;
    char thirdvalue = 'a';
    int *p1, *p2;
    char *p3;

    p1 = &firstvalue;  // p1 = address of firstvalue
    p2 = &secondvalue; // p2 = address of secondvalue
    p3 = &thirdvalue;  // p3 = address of thirdvalue
    *p1 = 10;          // value pointed to by p1 = 10
    *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
    p1 = p2;           // p1 = p2 (value of pointer is copied)
    *p1 = 20;          // value pointed to by p1 = 20
    *p3 = 'b';         // value pointed to by p3 = 'b'

    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';
    cout << "thirdvalue is " << thirdvalue << '\n';

    return 0;
}
```

**Note:** While solving pointers question, you should use pen and paper and draw things to get a better idea.

### Null Pointer

Consider the following statement:

```cpp
int *p;
```

Here we have created a pointer variable that contains a garbage value. In order to dereference the pointer, we will try reading out the value at the garbage stored in the pointer. This will lead to unexpected results or segmentation faults. Hence we should never leave a pointer uninitialized and instead initialize it to NULL, so as to avoid unexpected behavior.

```cpp
int *p = NULL; // NULL is a constant with a value 0
int *q = 0;    // Same as above
```

So now if we try to dereference the pointer, we will get a segmentation fault as 0 is a reserved memory address.

### Pointer Arithmetic

Arithmetic operations on pointers behave differently than they do on simple data types we studied earlier. Only addition and subtraction operations are allowed; the others aren’t allowed on pointers. But both addition and subtraction have a slightly different behavior with pointers, according to the size of the data type to which they point.

For example, `char` always has a size of 1 byte, `short` is generally larger than that, and `int` and `long` are even larger; the exact size of these being dependent on the system. For example, let's imagine that in a given system, `char` takes 1 byte, `short` takes 2 bytes, and `long` takes 4.

Suppose now that we define three pointers in this compiler:

```cpp
char *mychar;
short *myshort;
long *mylong;
```

and that we know that they point to the memory locations 1000, 2000, and 3000, respectively.

Therefore, if we write:

```cpp
++mychar;
++myshort;
++mylong;
```

`mychar`, as one would expect, would contain the value 1001. But not so obviously, `myshort` would contain the value 2002, and `mylong` would contain 3004, even though they have each been incremented only once. The reason is that when adding one to a pointer, the pointer is made to point to the following element of the same type, and, therefore, the size in bytes of the type it points to is added to the pointer.

This is applicable both when adding and subtracting any number to a pointer. It would happen exactly the same if we wrote:

```cpp
mychar = mychar + 1;
myshort = myshort + 1;
mylong = mylong + 1;
```

Essentially, these are the four possible combinations of the dereference operator with both the prefix and suffix versions of the increment operator (the same being applicable also to the decrement operator):

1. `*p++`   // same as `*(p++)`: increment pointer, and dereference unincremented address
2. `*++p`   // same as `*(++p)`: increment pointer, and dereference incremented address
3. `++*p`   // same as `++(*p)`: dereference pointer, and increment the value it points to
4. `(*p)++` // dereference pointer, and post-increment the value it points to

Pointers may be compared by using relational operators, such as `==`, `<`, and `>`. If `p1` and `p2` point to variables that are related to each other, such as elements of the same array, then `p1` and `p2` can be meaningfully compared.

### Pointer and Arrays

Pointers and arrays are intricately linked. An array is actually a pointer that points to the first element of the array. Because the array variable is a pointer, you can dereference it, which returns array element 0.

Consider the following code:

```cpp
int a[] = {1, 2, 3, 4, 5};
int *b = &a[0];
cout << b << endl;
cout << a << endl;
cout << *b << endl; // This will print 1
```

Both `b` and `a` will print the same address as they are referring to the first element of the array. Also in arrays - `a[i]` is the same as `*(a + i)`.

Consider an example for the same–

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout << *(a + 2) << endl;
}
```

**Output:**

```
3
```

### Differences between arrays and pointers:

1. **The `sizeof` operator:**

   `sizeof(array)` returns the amount of memory used by all elements in the array, whereas `sizeof(pointer)` only returns the amount of memory used by the pointer variable itself.

   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       int a[5] = {1, 2, 3, 4, 5};
       int *b = &a[0];
       cout << sizeof(a) << endl;
       cout << sizeof(b) << endl;
   }


   ```

   **Output:**

   ```
   20
   8   // Size of pointer is compiler dependent. Here it is 8.
   ```

2. **The `&` operator:**

   In the example above `&a` is an alias for `&a[0]` and returns the address of the first element in the array.

   `&b` returns the address of the pointer.

3. **Pointer variable can be assigned a value whereas array variable cannot be.**

   ```cpp
   int a[10];
   int *p;

   p = a;   // legal
   a = p;   // illegal
   ```

4. **Arithmetic on pointer variable is allowed, but not allowed on array variable.**

   ```cpp
   p++;   // Legal
   a++;   // illegal
   ```

### Double Pointer

As we know by now that pointers are variables that store the address of other variables, so we can create variables that store the address of the pointer itself, i.e., a pointer to a pointer. Let’s see how can we create one.

```cpp
int a = 10;
int *p = &a;
int **q = &p;
```

Here `q` is a pointer to a pointer, i.e., a double pointer, as indicated by `**`.

Consider the following code for better understanding:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    int **q = &p;

    // Next three statements will print the same value, i.e., the address of a
    cout << &a << endl;
    cout << p << endl;
    cout << *q << endl;

    // Next two statements will print the same value, i.e., the address of p
    cout << &p << endl;
    cout << q << endl;

    // Next two statements will print the same value, i.e., the value of a which is 10
    cout << a << endl;
    cout << *p << endl;
    cout << **q << endl;
}
```

### Void Pointer

A void pointer is a generic pointer; it has no associated type with it. A void pointer can hold the address of any type and can be typecasted to any type. Void pointer is declared normally the way we do for pointers.

```cpp
void *ptr;
```

This statement will create a void pointer.

**Example:**

```cpp
void *v;
int *i;
int ivar;
char chvar;
float fvar;
v = &ivar;  // valid
v = &chvar; // valid
v = &fvar;  // valid
i = &ivar;  // valid
i = &chvar; // invalid
i = &fvar;  // invalid
```

Thus we can use a void pointer to store the address of any variable.
