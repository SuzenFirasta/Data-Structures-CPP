# 🚀 Advanced Concepts in Object-Oriented Programming (OOP) in C++

## 🔄 Shallow and Deep Copy

### Shallow Copy
A **shallow copy** duplicates all the member field values of an object, including pointers. However, the memory pointed to by the pointer is not copied, meaning that both the original object and the copied object will point to the same memory address. This can lead to issues, especially with dynamic memory, as changes in one object will reflect in the other.

> **Note:** The assignment operator `=` and the default copy constructor in C++ make a shallow copy by default.

### Deep Copy
A **deep copy** not only duplicates the object's fields but also creates a copy of any dynamically allocated memory. This ensures that the original and copied objects do not share the same memory address, preventing unintended side effects. To implement deep copying, you need to define your own copy constructor and overload the assignment operator.

### 💻 Example: Shallow vs Deep Copy
```cpp
class Student {
    int age;
    char *name;

public:
    // Parameterized constructor
    Student(int age, char *name) {
        this->age = age;
        
        // Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy constructor for deep copy
    Student(Student const &s) {
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
};
```

### 📊 Shallow Copy Visualization
```plaintext
Original Object         Shallow Copy
-------------------     -------------------
| age: 20           |   | age: 20           |
| name: 0x7ffeee4a0 | --> | name: 0x7ffeee4a0 |
-------------------     -------------------
```

### 📊 Deep Copy Visualization
```plaintext
Original Object         Deep Copy
-------------------     -------------------
| age: 20           |   | age: 20           |
| name: 0x7ffeee4a0 |   | name: 0x7ffeee4c0 |
-------------------     -------------------
```

## 📝 Initialization List
An **initialization list** allows direct assignment of values to data members when an object is created. This approach is mandatory in certain situations, such as:
- When the base class has no default constructor.
- When the data members are `const`.
- When the data members have the same name as the parameters.
- When using reference-type data members.

### 💻 Example: Initialization List
```cpp
class Student {
    const int rollNumber;
    int age;
    int &x;

public:
    // Initialization list is mandatory here
    Student(int r, int age) : rollNumber(r), age(age), x(this->age) {}
};
```

## ⚙️ Constant Functions
**Constant functions** do not modify any member variables of the object. Only constant objects can invoke these functions.

### 💻 Example: Constant Function
```cpp
class Student {
    int age;

public:
    int getAge() const {  // Constant function
        return age;
    }
};
```

## 📌 Static Members
**Static members** are shared among all objects of a class. They are not tied to any specific object but to the class itself. Static members can be both variables and functions.

### 💻 Example: Static Members
```cpp
class Student {
    static int totalStudents;  // Static variable to keep track of total students

public:
    int rollNumber;

    Student() {
        totalStudents++;
    }

    static int getTotalStudents() {  // Static function
        return totalStudents;
    }
};

// Initialize static member
int Student::totalStudents = 0;

int main() {
    Student s1, s2, s3;
    cout << Student::getTotalStudents() << endl;  // Output: 3
}
```

## ➕ Operator Overloading
Operator overloading allows you to redefine the way operators work for user-defined types (objects). This makes the code more intuitive and easier to read.

### 💻 Example: Overloading the `+` Operator
```cpp
class Fraction {
    int numerator, denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {}

    // Overload the + operator
    Fraction operator+(Fraction const &f2) const {
        int lcm = denominator * f2.denominator;
        int num = (numerator * f2.denominator) + (f2.numerator * denominator);
        return Fraction(num, lcm);
    }
};
```

## 🔄 Dynamic Array Class
A dynamic array class can be implemented to handle arrays that can grow in size as needed, unlike static arrays with a fixed size.

### 💻 Example: Implementing a Dynamic Array Class
```cpp
class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

public:
    // Constructor with initial capacity
    DynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    // Deep copy constructor
    DynamicArray(DynamicArray const &d) {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++) {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    // Function to add elements to the array
    void add(int element) {
        if (nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex++] = element;
    }

    // Function to get an element by index
    int get(int i) const {
        if (i < nextIndex) {
            return data[i];
        }
        return -1;  // Return -1 if index is out of bounds
    }

    // Print the entire array
    void print() const {
        for (int i = 0; i < nextIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
```

## 💡 Summary
Advanced concepts in Object-Oriented Programming, such as shallow and deep copying, initialization lists, constant functions, static members, and operator overloading, provide powerful tools for designing robust and efficient software. By understanding and utilizing these features, you can create more flexible, reusable, and maintainable code in C++.

---

