## 🧩 Introduction to Linked Lists

### 📜 What is a Linked List?

A **Linked List** is a linear data structure where each element is a separate object called a **node**. Each node contains two parts:
1. **Data**: The value stored in the node.
2. **Pointer**: A reference to the next node in the sequence.

Unlike arrays, elements in a linked list are not stored in contiguous memory locations. Instead, each node points to the next, forming a chain-like structure.

### 🔑 Key Characteristics:
- **Dynamic Size**: Unlike arrays, the size of a linked list can grow or shrink dynamically.
- **Ease of Insertion/Deletion**: Nodes can be easily added or removed without rearranging the entire structure.
- **No Contiguous Memory Allocation**: Nodes are stored in scattered memory locations, linked together by pointers.

### 📚 Linked List Types:
- **Singly Linked List**: Each node points to the next node and the last node points to `NULL`.
- **Doubly Linked List**: Each node contains two pointers, one pointing to the next node and one to the previous node.
- **Circular Linked List**: The last node points back to the first node, creating a circular structure.

![Linked List Types](https://via.placeholder.com/400x200)  
*Figure 1: Different Types of Linked Lists*

## 🛠 Operations on Linked Lists

### 1. **Printing a Linked List**

To print the linked list, traverse the list from the `head` node to the `tail` node, printing each node's data along the way.

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
```

### 2. **Insertion in Linked Lists**

Insertion can occur at different positions:
- **At the End**: Simple insertion at the tail.
- **At the Beginning**: Insert before the current head and update the head pointer.
- **At the Middle**: Traverse to the desired position and insert the new node.

### 💻 Example: Insertion in Linked Lists
```cpp
Node* insertNode(Node* head, int i, int data) {
    Node* newNode = new Node(data);
    if (i == 0) {  // Insert at the beginning
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < i - 1) {  // Traverse to the correct position
        temp = temp->next;
        count++;
    }

    if (temp != nullptr) {  // Insert at the middle or end
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
```

### 3. **Deletion in Linked Lists**

Deletion can also occur at different positions:
- **From the Head**: Remove the head node and update the head pointer.
- **From the Middle/End**: Traverse to the desired position and adjust pointers to bypass the node to be deleted.

### 💻 Example: Deletion in Linked Lists
```cpp
Node* deleteNode(Node* head, int i) {
    if (head == nullptr) return head;

    if (i == 0) {  // Delete the head node
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < i - 1) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr && temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    return head;
}
```

## 🔄 Advanced Linked List Operations

### 1. **Finding the Midpoint of a Linked List**

To find the midpoint, use two pointers:
- **Slow Pointer**: Moves one node at a time.
- **Fast Pointer**: Moves two nodes at a time.

When the fast pointer reaches the end, the slow pointer will be at the midpoint.

```cpp
Node* findMidpoint(Node* head) {
    if (head == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

### 2. **Merging Two Sorted Linked Lists**

Merge two sorted linked lists by comparing the nodes and linking them in sorted order.

```cpp
Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* mergedHead = nullptr;
    if (head1->data < head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeSortedLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeSortedLists(head1, head2->next);
    }

    return mergedHead;
}
```

### 3. **Reversing a Linked List**

Reversing a linked list can be done either iteratively or recursively.

#### Recursive Approach:
```cpp
Node* reverseLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* smallAns = reverseLL(head->next);
    head->next->next = head;
    head->next = nullptr;
    return smallAns;
}
```

#### Iterative Approach:
Use three pointers (`prev`, `current`, and `next`) to iteratively reverse the linked list.

```cpp
Node* reverseLLIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
```

### 4. **Merge Sort on Linked Lists**

Merge sort can be applied to linked lists similarly to arrays. Find the midpoint, divide the list, recursively sort the halves, and then merge them.

### 5. **Variations of Linked Lists**

- **Doubly Linked List**: Nodes have pointers to both the next and previous nodes.
- **Circular Linked List**: The last node points back to the first node.

## 📚 Practice Problems

- [HackerRank: Linked Lists Practice](https://www.hackerrank.com/domains/data-structures?filters%5Bsubdomains%5D%5B%5D=linked-lists)
- [LeetCode: Linked List Problems](https://leetcode.com/tag/linked-list/)

