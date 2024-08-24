
# 🌳 Binary Trees

## 📝 Introduction
A **Binary Tree** is a hierarchical data structure in which each node has at most two children, commonly referred to as the **left** and **right** child. This structure is widely used in various algorithms and applications, making it fundamental to understanding data structures and algorithms.

### 🌐 Structure of a Binary Tree
A binary tree is composed of nodes, where each node contains:
- A **data element**.
- A **left** pointer pointing to the left child (which may be `NULL` if there's no left child).
- A **right** pointer pointing to the right child (which may be `NULL` if there's no right child).

![Binary Tree Structure](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg)

### 🛠 Formal Definition:
A **Binary Tree** is either:
1. **Empty**: Represented by a `NULL` pointer.
2. **Non-Empty**: Composed of a root node and two subtrees, each of which is a binary tree.

## 🧩 Types of Binary Trees
Binary trees can be classified into several types based on their structure:

### 1. **Full Binary Tree**
- Every node has either 0 or 2 children.

```plaintext
    1
   / \
  2   3
```

### 2. **Complete Binary Tree**
- All levels are completely filled except possibly the last level, which is filled from left to right.

```plaintext
    1
   / \
  2   3
 / \
4   5
```

### 3. **Perfect Binary Tree**
- All internal nodes have two children, and all leaf nodes are at the same level.

```plaintext
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

### 4. **Degenerate Tree**
- Each parent node has only one child, making it resemble a linked list.

```plaintext
    1
     \
      2
       \
        3
```

### 5. **Balanced Binary Tree**
- The difference in height between the left and right subtrees of any node is at most one.

```plaintext
    1
   / \
  2   3
 / \
4   5
```

## 🖼 Binary Tree Representation
Binary trees can be represented in two main ways:

### 1. **Sequential Representation**
- Uses an array to store nodes.
- For a node at index `i`, the left child is stored at `2*i`, and the right child is stored at `2*i + 1`.

```plaintext
Index:  1  2  3  4  5
Array: [1, 2, 3, 4, 5]
Tree: 
    1
   / \
  2   3
 / \
4   5
```

### 2. **Linked List Representation**
- Each node is represented as a structure or class with pointers to the left and right children.

```cpp
class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
```

## 🛠 Operations on Binary Trees

### 🌳 Taking Input and Printing
#### Recursive Printing of Binary Tree:
```cpp
void printTree(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL) {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
```

#### Level-wise Input Taking:
```cpp
BinaryTreeNode* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << ": ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            front->left = new BinaryTreeNode(leftChildData);
            pendingNodes.push(front->left);
        }

        cout << "Enter right child of " << front->data << ": ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            front->right = new BinaryTreeNode(rightChildData);
            pendingNodes.push(front->right);
        }
    }
    return root;
}
```

### 📊 Counting Nodes
```cpp
int countNodes(BinaryTreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

### 🔀 Binary Tree Traversals
Traversing a binary tree means visiting all nodes in a specific order. Common traversal methods include:

1. **Inorder (LEFT → ROOT → RIGHT)**
    ```cpp
    void inorder(BinaryTreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    ```

2. **Preorder (ROOT → LEFT → RIGHT)**
    ```cpp
    void preorder(BinaryTreeNode* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    ```

3. **Postorder (LEFT → RIGHT → ROOT)**
    ```cpp
    void postorder(BinaryTreeNode* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    ```

4. **Level Order Traversal**
    ```cpp
    void levelOrderTraversal(BinaryTreeNode* root) {
        if (root == NULL) return;
        queue<BinaryTreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            BinaryTreeNode* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != NULL) q.push(front->left);
            if (front->right != NULL) q.push(front->right);
        }
    }
    ```

### 🏗 Constructing a Binary Tree
#### From Inorder and Preorder Traversals:
Given the inorder and preorder sequences, the binary tree can be constructed recursively.

```cpp
BinaryTreeNode* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    if (inS > inE) return NULL;
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode* buildTree(int* in, int* pre, int size) {
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
```

### 📏 Calculating the Diameter of a Binary Tree
The diameter of a tree is the number of nodes on the longest path between any two nodes.

#### Initial Approach:
```cpp
int height(BinaryTreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode* root) {
    if (root == NULL) return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
```

#### Optimized Approach:
In this approach, height and diameter are calculated simultaneously to reduce time complexity.
```cpp
pair<int, int> heightDiameter(BinaryTreeNode*

 root) {
    if (root == NULL) return {0, 0};

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    return {height, diameter};
}
```

## 🧠 Time Complexity Analysis
- **Height Calculation:** `O(n)` where `n` is the number of nodes.
- **Initial Diameter Calculation:** `O(n*h)` where `h` is the height, which can be `O(n^2)` in the worst case.
- **Optimized Diameter Calculation:** `O(n)`.

## 🎯 Practice Problems
- [HackerRank: Tree Top View](https://www.hackerrank.com/challenges/tree-top-view/problem)
- [CodeChef: Binary Tree KK](https://www.codechef.com/problems/BTREEKK)
- [SPOJ: Tree Verse](https://www.spoj.com/problems/TREEVERSE/)
- [HackerEarth: Largest Cycle in a Tree](https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/approximate/largest-cycle-in-a-tree-9113b3ab/)

---

*This README.md is designed to be a comprehensive guide to understanding binary trees, with code snippets, diagrams, and detailed explanations.*
```

This README.md structure provides a rich, detailed, and engaging introduction to binary trees, using diagrams, code examples, and clear explanations. It serves both as a study guide and a reference document for anyone looking to understand or implement binary trees.