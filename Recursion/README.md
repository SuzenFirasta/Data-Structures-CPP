# Recursion in C++

Welcome to the fascinating world of **Recursion** in C++! This guide will walk you through the concept of recursion, its importance, and how to implement it in your C++ programs.

## 🚀 What is Recursion?

In the realm of computer science, **recursion** is like a mirror reflecting itself infinitely. It’s a method where a solution to a problem depends on solutions to smaller instances of the same problem. Imagine solving a puzzle where every piece is a smaller version of the complete picture—this is recursion in action!

Recursion allows a function to call itself, breaking down complex problems into more manageable, smaller problems, ultimately leading to an elegant solution.

## 🛠️ How Does Recursion Work?

A recursive function typically follows three key steps:

1. **Base Case:**  
   Every recursive function needs a stopping point, known as the base case. This is where the function halts its self-calling journey. Without a base case, a recursive function would continue indefinitely, leading to a stack overflow!

2. **Recursive Call:**  
   The heart of recursion is where the function calls itself on a smaller version of the problem. This step must be carefully designed to ensure it approaches the base case.

3. **Small Calculation:**  
   Along with each recursive call, a small calculation is usually performed. This calculation might occur before or after the recursive call, depending on the nature of the problem.

## 💡 Example: Factorial of a Number

Let’s dive into a classic example: calculating the factorial of a number using recursion.

```cpp
#include<iostream>
using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1; // Base Case
    }
    return n * fact(n - 1); // Recursive Call with Small Calculation
}

int main() {
    int num;
    cin >> num;
    cout << fact(num);
    return 0;
}
```

**Output:**  
For `num = 5`, the output will be `120`.

### 🧠 Understanding the Example

- We recursively call the `fact` function until `n` becomes 0, which is our base case.
- The function then unwinds, multiplying the numbers as it returns, eventually yielding the factorial of the original number.

## 🌱 Example: Fibonacci Series

Another classic example is the Fibonacci series, where each number is the sum of the two preceding ones.

```cpp
int fibo(int n) {
    if (n == 0 || n == 1) {
        return n; // Base Case
    }
    int a = fibo(n - 1); // Recursive Call
    int b = fibo(n - 2); // Recursive Call
    return a + b; // Small Calculation
}
```

**Explanation:**

- The Fibonacci function makes two recursive calls.
- It first calculates `fibo(n-1)`, then `fibo(n-2)`, and finally sums them up.

  
## Diagram 


Let's create simpler line diagrams using text to illustrate the recursive processes for both the factorial calculation and the Fibonacci series.

### 1. Factorial Calculation

```
fact(5)
  |
  |---> fact(4)
         |
         |---> fact(3)
                |
                |---> fact(2)
                       |
                       |---> fact(1)
                              |
                              |---> fact(0) --> returns 1
                       |
                       ---> returns 1 * 1 = 1
                |
                ---> returns 2 * 1 = 2
         |
         ---> returns 3 * 2 = 6
  |
  ---> returns 4 * 6 = 24
|
---> returns 5 * 24 = 120
```

### 2. Fibonacci Calculation

```
fibo(5)
  |
  |---> fibo(4)
  |      |
  |      |---> fibo(3)
  |      |      |
  |      |      |---> fibo(2)
  |      |      |      |
  |      |      |      |---> fibo(1) --> returns 1
  |      |      |      |
  |      |      |      ---> fibo(0) --> returns 0
  |      |      |
  |      |      ---> returns 1 + 0 = 1
  |      |
  |      ---> fibo(2)
  |             |
  |             |---> fibo(1) --> returns 1
  |             |
  |             ---> fibo(0) --> returns 0
  |
  ---> fibo(3)
         |
         |---> fibo(2)
         |      |
         |      |---> fibo(1) --> returns 1
         |      |
         |      ---> fibo(0) --> returns 0
         |
         ---> fibo(1) --> returns 1
```

These text-based line diagrams should give you a straightforward understanding of the recursive process for both examples.

### 🔄 Recursion & Mathematical Induction

Recursion is deeply connected to the **Principle of Mathematical Induction** (PMI). When proving theorems with PMI, we show that the base case is true and that the truth of case `k` implies the truth of case `k+1`. Similarly, in recursion, the base case corresponds to the initial condition, and the recursive calls reflect the inductive step.

## 📚 Conclusion

Recursion is a powerful tool in a programmer's toolkit, allowing for elegant solutions to complex problems. It challenges the mind to think differently, breaking down large problems into smaller, more manageable pieces.

# Note

1. When traversing an array from the end, always ensure that you start from the index `size - 1`. This approach is crucial for correctly accessing the last element of the array. For a detailed explanation and implementation, refer to [10_Last_Index.cpp](./10_Last_Index.cpp).

2. While traversing an array in recursive algorithms on arrays, the index returned from a recursive call is usually relative to the sub-array being processed. To get the correct index in the original array, you typically add 1 to the index returned by the recursive call, accounting for the element that was excluded from the sub-array during that recursive call.


Happy coding, and may your recursive functions always find their base case! ✨

---

