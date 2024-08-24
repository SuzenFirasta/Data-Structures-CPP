# 🌟 Advanced Concepts in Object-Oriented Programming (OOP) in C++

Object-Oriented Programming (OOP) encompasses four fundamental concepts that form the backbone of designing robust and maintainable software. These concepts are:

- **Abstraction**
- **Encapsulation**
- **Inheritance**
- **Polymorphism**

## 🧩 Abstraction & Encapsulation

### 🚗 Real-World Example:
Imagine you are driving a car. To stop the car, you simply press the brake pedal. You don't need to understand the intricate mechanisms behind how the brake system works. This is **abstraction** in action. The complexity is hidden, and only the necessary details are exposed.

Similarly, the car’s brake system is enclosed within the car's body, and its internal workings are hidden from the user. This is **encapsulation**—grouping the data and the methods that operate on that data into a single unit (the car in this case).

### 📊 Comparison of Abstraction and Encapsulation

| Concept        | Description | Example |
|----------------|-------------|---------|
| **Abstraction**  | Hides the complexity and shows only the necessary details to the user. | The brake pedal allows you to stop the car without knowing the internal mechanisms. |
| **Encapsulation** | Encases the data and the methods operating on the data within a single unit, and restricts access to some of the object’s components. | The entire braking system is enclosed within the car. |

### 💻 Example: Encapsulation in C++
```cpp
class Car {
private:
    int speed;
    void brake() {
        speed = 0;
    }

public:
    void applyBrake() {
        brake();
        cout << "Car stopped!" << endl;
    }
};
```

## 🧬 Inheritance

**Inheritance** allows a class to inherit properties and behaviors from another class. This promotes code reuse and the creation of hierarchical class relationships.

### 🚗 Example: Vehicle Hierarchy

Imagine you have different types of vehicles like cars, bicycles, and trucks. These vehicles share common attributes like color and maximum speed. Instead of repeating these attributes, we create a **base class** `Vehicle` and derive `Car`, `Bicycle`, and `Truck` from it.

### 📊 Inheritance Types

| Inheritance Type     | Description | Diagram |
|----------------------|-------------|---------|
| **Single Inheritance** | A single derived class inherits from one base class. | ![Single Inheritance](https://via.placeholder.com/150) |
| **Multi-level Inheritance** | A chain of classes where a derived class inherits from another derived class. | ![Multi-level Inheritance](https://via.placeholder.com/150) |
| **Multiple Inheritance** | A single derived class inherits from more than one base class. | ![Multiple Inheritance](https://via.placeholder.com/150) |
| **Multipath Inheritance** | Involves multiple paths leading to the same base class. | ![Multipath Inheritance](https://via.placeholder.com/150) |
| **Hierarchical Inheritance** | Multiple derived classes inherit from a single base class. | ![Hierarchical Inheritance](https://via.placeholder.com/150) |
| **Hybrid Inheritance** | A combination of more than one type of inheritance. | ![Hybrid Inheritance](https://via.placeholder.com/150) |

### 💻 Example: Inheritance in C++
```cpp
class Vehicle {
protected:
    int numTyres;

public:
    string color;
};

class Car : public Vehicle {
public:
    int numGears;

    void print() {
        cout << "NumTyres: " << numTyres << endl;
        cout << "Color: " << color << endl;
        cout << "NumGears: " << numGears << endl;
    }
};
```

## 🔄 Polymorphism

**Polymorphism** means "many forms". In OOP, it refers to the ability of a function to behave differently based on the object that invokes it.

### 📊 Types of Polymorphism

| Type                     | Description | Example |
|--------------------------|-------------|---------|
| **Compile-time Polymorphism** | Achieved through function overloading or operator overloading, where the function to be executed is determined at compile time. | Overloading the `+` operator to add two `Fraction` objects. |
| **Run-time Polymorphism** | Achieved through function overriding, where the function to be executed is determined at runtime. | Using a `print()` function in a base class and overriding it in a derived class. |

### 💻 Example: Compile-time Polymorphism (Function Overloading)
```cpp
int test(int a) {
    return a;
}

int test(int a, int b) {
    return a + b;
}

int test() {
    return 0;
}
```

### 💻 Example: Run-time Polymorphism (Function Overriding)
```cpp
class Vehicle {
public:
    virtual void print() {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    void print() override {  // Override the print function
        cout << "Car" << endl;
    }
};
```

## 🧭 Pure Virtual Functions and Abstract Classes

A **pure virtual function** is a function that has no implementation in the base class and must be implemented in derived classes. A class containing at least one pure virtual function is known as an **abstract class**.

### 💻 Example: Pure Virtual Function
```cpp
class Vehicle {  // Abstract class
public:
    virtual void print() = 0;  // Pure virtual function
};

class Car : public Vehicle {
public:
    void print() override {  // Must implement the pure virtual function
        cout << "Car" << endl;
    }
};
```

## 🛡 Friend Functions and Classes

**Friend functions** and **friend classes** allow external functions or classes to access private and protected members of a class.

### 💻 Example: Friend Function
```cpp
class Truck {
private:
    int x;

    friend void test();  // Friend function declaration

public:
    int z;
};

void test() {
    Truck t;
    t.x = 10;  // Accessing private member x
    cout << "Truck x: " << t.x << endl;
}
```

### 💻 Example: Friend Class
```cpp
class Bus {
public:
    void print();
};

class Truck {
private:
    int x;

    friend class Bus;  // Bus is a friend class

public:
    int z;
};

void Bus::print() {
    Truck t;
    t.x = 10;  // Accessing private member x
    cout << "Truck x: " << t.x << endl;
}
```

## 💡 Summary

These advanced OOP concepts are crucial for building scalable and maintainable software systems. By mastering **abstraction**, **encapsulation**, **inheritance**, and **polymorphism**, you can create flexible and reusable code. Understanding **friend functions**, **abstract classes**, and **pure virtual functions** further enhances your ability to design sophisticated C++ applications.

---
