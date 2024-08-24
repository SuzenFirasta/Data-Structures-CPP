# 🥞 Stacks in Data Structures

## 📜 Introduction to Stacks

A **stack** is a linear data structure that follows the Last In, First Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed. Think of it as a stack of books: you can only remove the top book first before accessing the ones below it.

### 🔑 Key Characteristics:
- **Abstract Data Type (ADT):** Stacks are an abstract data type, meaning they are defined by their behavior (operations) rather than their implementation.
- **LIFO Structure:** The last element pushed onto the stack is the first one to be popped off.
- **Common Operations:**
  - **Push:** Add an element to the top of the stack.
  - **Pop:** Remove the top element from the stack.
  - **Top/Peek:** View the top element without removing it.
  - **isEmpty:** Check if the stack is empty.
  - **Size:** Get the number of elements in the stack.

### 📚 Stack Analogy:
Imagine a stack of books. You can only remove the top book before accessing the next one beneath it. Similarly, you can only add a new book to the top of the stack.

![Stack of Books](https://via.placeholder.com/400x200)  
*Figure 1: Illustration of a Stack of Books (LIFO Structure)*

## 🛠 Operations on Stacks

| Operation | Description | Function Name |
|-----------|-------------|---------------|
| **Push**  | Insert an element at the top of the stack. | `push()` |
| **Pop**   | Remove the top element from the stack. | `pop()`  |
| **Top/Peek** | Retrieve the top element without removing it. | `top()` |
| **isEmpty** | Check if the stack is empty. | `isEmpty()` |
| **Size**  | Return the number of elements in the stack. | `size()` |

### 💻 Example: Basic Stack Operations in C++
```cpp
#include <iostream>
#include <climits>

class StackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    void push(int element) {
        if (nextIndex == capacity) {
            std::cout << "Stack full" << std::endl;
            return;
        }
        data[nextIndex++] = element;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
```

## 📏 Dynamic Stacks

One limitation of the above implementation is the fixed size of the stack. To overcome this, we can create a **dynamic stack** where the size is doubled whenever the stack reaches its capacity.

### 💻 Example: Dynamic Stack in C++
```cpp
class DynamicStack {
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicStack() {
        data = new int[4];  // Initial capacity of 4
        nextIndex = 0;
        capacity = 4;
    }

    void push(int element) {
        if (nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN;
        }
        return data[--nextIndex];
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    int size() {
        return nextIndex;
    }
};
```

## 🔧 Stack Using Templates

To create a more flexible stack that can handle any data type (e.g., int, char, float), we can use **templates**.

### 💻 Example: Template-Based Stack
```cpp
#include <iostream>
#include <climits>

template <typename T>
class StackUsingArray {
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray() {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    void push(T element) {
        if (nextIndex == capacity) {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        return data[--nextIndex];
    }

    T top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    int size() {
        return nextIndex;
    }
};
```

## 🔗 Stack Using Linked Lists

Stacks can also be implemented using **linked lists**. This approach provides more flexibility with dynamic memory allocation and avoids the need for resizing.

### 📊 Comparison: Array vs Linked List Implementation

| Feature                 | Array Implementation | Linked List Implementation |
|-------------------------|----------------------|----------------------------|
| **Memory Allocation**   | Fixed or dynamically resized array. | Dynamic allocation per node. |
| **Size Limitation**     | Must be predefined or resized dynamically. | No predefined limit. |
| **Memory Efficiency**   | May waste space if the stack is underutilized. | More memory-efficient for dynamic use. |
| **Implementation Complexity** | Easier to implement and understand. | Slightly more complex due to pointers. |

### 💻 Example: Stack Using Linked List
```cpp
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        T topData = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return topData;
    }

    T top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        return head->data;
    }
};
```

## 📚 In-Built Stack Using STL

C++ Standard Template Library (STL) provides a built-in stack class that can be used directly without implementing the stack data structure from scratch.

### 💻 Example: Using STL Stack
```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Top element: " << st.top() << std::endl;  // Output: 30
    st.pop();
    std::cout << "Top element after pop: " << st.top() << std::endl;  // Output: 20

    std::cout << "Size of stack: " << st.size() << std::endl;  // Output: 2

    if (st.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    return 0;
}
```

## 🔗 Useful Links and Practice Problems

- [HackerRank: Equal Stacks](https://www.hackerrank.com/challenges/equal-stacks/problem)
- [HackerRank: Simple Text Editor](https://www.hackerrank.com/ch

allenges/simple-text-editor/problem)
- [Techie Delight: Design a Stack with Minimum Element](https://www.techiedelight.com/design-a-stack-which-returns-minimum-element-without-using-auxiliary-stack/)
- [HackerEarth: Monk and Order of Phoenix](https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/monk-and-order-of-phoenix/)

---
