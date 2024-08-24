# 🚌 Queues in Data Structures

## 📜 Introduction to Queues

A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue will be the first one to be removed. This is similar to a queue of people waiting in line; the first person to get in line is the first to be served.

### 🔑 Key Characteristics:
- **Abstract Data Type (ADT):** Queues are defined by their behavior rather than their implementation.
- **FIFO Structure:** The first element enqueued (inserted) is the first one dequeued (removed).
- **Common Operations:**
  - **Enqueue:** Add an element to the end of the queue.
  - **Dequeue:** Remove an element from the front of the queue.
  - **Front:** Access the element at the front of the queue without removing it.
  - **isEmpty:** Check if the queue is empty.
  - **Size:** Get the number of elements in the queue.

### 📚 Queue Analogy:
Imagine a queue at a movie ticket counter. The first person in line gets their ticket first, and new people join at the end of the line.

![Queue Analogy](https://via.placeholder.com/400x200)  
*Figure 1: Illustration of a Queue at a Ticket Counter (FIFO Structure)*

## 🛠 Operations on Queues

| Operation | Description | Function Name |
|-----------|-------------|---------------|
| **Enqueue**  | Insert an element at the end of the queue. | `enqueue()` |
| **Dequeue**  | Remove the element at the front of the queue. | `dequeue()`  |
| **Front**    | Retrieve the element at the front without removing it. | `front()` |
| **isEmpty**  | Check if the queue is empty. | `isEmpty()` |
| **Size**     | Return the number of elements in the queue. | `getSize()` |

### 💻 Example: Basic Queue Operations in C++
```cpp
#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray {
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s) {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T element) {
        if (size == capacity) {
            cout << "Queue Full!" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }
};
```

## 📏 Dynamic Queues

One limitation of the above implementation is the fixed size of the queue. To overcome this, we can create a **dynamic queue** where the size doubles when the queue reaches its capacity.

### 💻 Example: Dynamic Queue in C++
```cpp
template <typename T>
class DynamicQueue {
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    DynamicQueue() {
        data = new T[4];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 4;
    }

    void enqueue(T element) {
        if (size == capacity) {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++) {
                newData[j++] = data[i];
            }
            for (int i = 0; i < firstIndex; i++) {
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};
```

## 🔧 Queue Using Linked Lists

Queues can also be implemented using **linked lists**. This approach provides more flexibility with dynamic memory allocation and avoids the need for resizing.

### 📊 Comparison: Array vs Linked List Implementation

| Feature                 | Array Implementation | Linked List Implementation |
|-------------------------|----------------------|----------------------------|
| **Memory Allocation**   | Fixed or dynamically resized array. | Dynamic allocation per node. |
| **Size Limitation**     | Must be predefined or resized dynamically. | No predefined limit. |
| **Memory Efficiency**   | May waste space if the queue is underutilized. | More memory-efficient for dynamic use. |
| **Implementation Complexity** | Easier to implement and understand. | Slightly more complex due to pointers. |

### 💻 Example: Queue Using Linked List
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
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        size--;
        return ans;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return head->data;
    }
};
```

## 📚 In-Built Queue Using STL

C++ Standard Template Library (STL) provides a built-in queue class that can be used directly without implementing the queue data structure from scratch.

### 💻 Example: Using STL Queue
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;  // Output: 10
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;  // Output: 20

    cout << "Size of queue: " << q.size() << endl;  // Output: 2

    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
```
