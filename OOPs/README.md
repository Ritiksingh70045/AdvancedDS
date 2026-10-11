# Object-Oriented Programming (OOP) in C++: Beginner-Friendly Guide & Codebase Reference

> A beginner-friendly guide to C++ OOP. It explains the four main OOP ideas, how objects work in memory, common design patterns, and a few stack problems. Examples are connected to the files in this repository.

---

## Table of Contents
1. [Repository Codebase Architecture & Summaries](#1-repository-codebase-architecture--summaries)

   - [Core Concepts & Memory Management](#core-concepts--memory-management)

   - [Inheritance & Hierarchy Mechanics](#inheritance--hierarchy-mechanics)

   - [Polymorphism & Low-Level Dispatch](#polymorphism--low-level-dispatch)

   - [Abstraction, Interfaces & System Designs](#abstraction-interfaces--system-designs)

   - [Data Structures & Coding Problems](#data-structures--coding-problems)

2. [Top 50 Interview Questions & Answers with Code](#2-top-50-interview-questions--answers-with-code)

   - [Module 1: Core OOP Fundamentals & Memory (Q1 – Q10)](#module-1-core-oop-fundamentals--memory)

   - [Module 2: Inheritance & The Diamond Problem (Q11 – Q18)](#module-2-inheritance--the-diamond-problem)

   - [Module 3: Polymorphism, VTABLE & Tricky Edge Cases (Q19 – Q28)](#module-3-polymorphism-vtable--tricky-edge-cases)

   - [Module 4: Abstraction, Interfaces & Design Patterns (Q29 – Q36)](#module-4-abstraction-interfaces--design-patterns)

   - [Module 5: Encapsulation, Static Members & Friendship (Q37 – Q43)](#module-5-encapsulation-static-members--friendship)

   - [Module 6: Problem-Solving & Stack-Based Expression Evaluation (Q44 – Q50)](#module-6-problem-solving--stack-based-expression-evaluation)

---

## 1. Repository Codebase Architecture & Summaries
This repository contains small C++ programs that demonstrate OOP concepts and problem-solving. The list below tells you what each file is meant to teach.

### Core Concepts & Memory Management
*   **`\1`**: Shows what can go wrong when an object stores a pointer and is copied normally. Both objects end up pointing to the same memory. Changing the value through one object changes what the other sees, and both may try to free the same memory, causing a double-free error.

*   **`\1`**: Shows a safer copy constructor. It creates a separate piece of memory for the new object and copies the value into it, so the two objects do not share the same pointer target.

*   **`\1` & `\1`**: Shows the order of constructors in a chain of parent and child classes: the parent is constructed first, then its child, and then the next child.

*   **`\1`**: Uses a database-connection example to show `static` members. A static variable is shared by every object of the class, while a static function can be called using the class name and can directly use only static members.

### Inheritance & Hierarchy Mechanics
*   **`\1`: Implements the classic **Diamond Problem**** with multiple inheritance (`D -> B, C -> A`). Demonstrates how `virtual public A` (Virtual Inheritance) prevents multiple copies of base class `A` inside object `D`.

*   **`\1`**: Shows that a class normally initializes its direct parent. The parent is responsible for initializing its own parent.

*   **`\1` & `\1`**: Shows how `friend class` gives another class permission to access private and protected members. Use this carefully because it allows access that would normally be blocked.

*   **`\1` & `\1`**: Compares a normal function made a friend with a method from another class made a friend. It also shows why a forward declaration may be needed to tell the compiler that a class exists.

### Polymorphism & Low-Level Dispatch
*   **`\1`**: Shows why two functions cannot have the same name and parameters but different return types only: when you call the function, the compiler would not know which one you meant.

*   **`\1`**: Shows operator overloading: the `+` operator is taught how to add two `Complex` objects.

*   **`\1` & `\1`**: Shows runtime polymorphism with `virtual` and `override`. The signatures must match for overriding; otherwise, the child function may hide the parent function instead.

*   **`\1` & `\1`: Highlights a classic C++ interview trap: **Virtual functions with default arguments****. The function body is chosen at runtime (dynamic dispatch), while the default parameter is bound at compile time based on the pointer type. Also illustrates constructor ordering (`Base -> Derived`) versus destructor ordering (`Derived -> Base`) alongside virtual destructors.

### Abstraction, Interfaces & System Designs
*   **`\1`**: Introduces pure virtual functions, written with `= 0`. A class with a pure virtual function is abstract, so you cannot create an object of that class directly.

*   **`\1`**: Uses `Shape` as a common parent. Every real shape must provide its own `area()` method.

*   **`\1`**: Shows an interface-like class that says printable items must implement `print()` and `scan()`. Classes such as `Document` and `Photo` provide the actual code.

*   **`\1`**: Shows several shape classes sharing one parent. Each shape can calculate its own area while being handled through a common `Shape` interface.

*   **`\1`**: Shows how different employee types calculate pay differently while sharing the same `Employee` interface.

*   **`\1`**: Shows a common media-player interface with separate classes for MP3, MP4, and VLC playback.

*   **`\1`**: Shows different notification types sharing a `send()` method. A protected logging method can be used by child classes, and a virtual destructor supports safe deletion through a base pointer.

*   **`\1`**: Shows different payment types sharing a common parent class and reusing validation code.

*   **`\1`: Implements the **Strategy Design Pattern****. The client `ShoppingCart` delegates payment to an interchangeable `PaymentStrategy` pointer (`CreditCard`, `UPI`, `Wallet`) at runtime.

### Data Structures & Coding Problems
*   **`\1`: Custom array-based `Stack` class implemented from scratch (`push`, `pop`, `peek`, `isEmpty`) with full bounds and underflow checking. Solves the **Evaluation of Postfix Expression (Reverse Polish Notation)****.

*   **`\1`: Solves the **Evaluation of Prefix Expression (Polish Notation)**** using an STL stack and right-to-left traversal.

---

## 2. Top 50 Interview Questions & Answers with Code
---

### Module 1: Core OOP Fundamentals & Memory
#### Q1. What are the four core pillars of Object-Oriented Programming? Explain each with a one-line practical intuition.
*   **Encapsulation**: **Encapsulation** means keeping data and the functions that work on it together in a class. Access labels such as `private` help stop outside code from changing internal data directly.

*   **Abstraction**: **Abstraction** means showing what an object can do while hiding the details of how it does it.

*   **Inheritance**: **Inheritance** lets a child class reuse or extend the data and functions of a parent class.

*   **Polymorphism**: **Polymorphism** means the same function call or operator can behave differently depending on the situation or the object's actual type.

---

#### Q2. What is the fundamental difference between Shallow Copy and Deep Copy? What is the Double-Free problem?
*   **Answer**:

    *   **Shallow Copy**: Default behavior when copying objects. It performs a bitwise copy of member variables. If the class contains raw pointers pointing to heap memory, both the original and cloned object will point to the exact same memory address.

    *   **Deep Copy**: Allocates fresh, distinct heap memory for the cloned object and copies the actual values from the source.

    *   **Double-Free Problem**: In shallow copy, when both objects go out of scope, their destructors execute `delete ptr;` on the exact same memory address twice, causing undefined behavior or a segmentation fault (`SIGSEGV`).

*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class DeepCopyDemo {

public:

    int* data;

    DeepCopyDemo(int val) {

        data = new int(val);

    }

    // Custom Deep Copy Constructor

    DeepCopyDemo(const DeepCopyDemo &source) {

        data = new int(*(source.data)); // Allocate separate memory

    }

    ~DeepCopyDemo() {

        delete data; // Safe: each instance owns unique heap memory

    }

};

int main() {

    DeepCopyDemo obj1(10);

    DeepCopyDemo obj2 = obj1; // Deep copy executed

    *obj2.data = 20;

    cout << "obj1: " << *obj1.data << endl; // 10

    cout << "obj2: " << *obj2.data << endl; // 20

    return 0;

}

```

---

#### Q3. Why must the parameter to a Copy Constructor always be passed by reference (`const ClassName &obj`) and not by value?
*   **Answer**:

    *   If the parameter were passed by value, C++ would need to make a copy just to pass the object into the copy constructor.

    *   To initialize that parameter, the copy constructor would be called again, which again passes by value, resulting in an **infinite recursion** until the call stack overflows.

    *   Passing a reference avoids making that extra copy. `const` also promises that the source object will not be changed through this parameter.

---

#### Q4. What is the "Rule of Three" and "Rule of Five" in C++?
*   **Answer**:

    *   **Rule of Three (C++03)**: If a class explicitly manages dynamic resources and defines any one of the following, it almost certainly needs to explicitly define all three:

        1. Destructor

        2. Copy Constructor

        3. Copy Assignment Operator (`operator=`)

    *   **Rule of Five (C++11)**: With modern C++ move semantics, if you define the above three, you should also define:

        4. Move Constructor

        5. Move Assignment Operator

*   **Code Skeleton**:

```cpp

class Resource {

    int* ptr;

public:

    Resource(int v) : ptr(new int(v)) {}

    ~Resource() { delete ptr; }                                // 1. Destructor

    Resource(const Resource& o) : ptr(new int(*o.ptr)) {}     // 2. Copy Ctor

    Resource& operator=(const Resource& o) {                   // 3. Copy Assign

        if (this != &o) { delete ptr; ptr = new int(*o.ptr); }

        return *this;

    }

    Resource(Resource&& o) noexcept : ptr(o.ptr) { o.ptr = nullptr; } // 4. Move Ctor

    Resource& operator=(Resource&& o) noexcept {                      // 5. Move Assign

        if (this != &o) { delete ptr; ptr = o.ptr; o.ptr = nullptr; }

        return *this;

    }

};

```

---

#### Q5. What is the execution order of Constructors and Destructors in multi-level inheritance?
*   **Answer**:

    *   **Constructors**: Executed top-down from **Base to Derived** (`A -> B -> C`). A child class cannot exist without its base class parts being initialized first.

    *   **Destructors**: Executed bottom-up in reverse order from **Derived to Base** (`C -> B -> A`). Child resources are freed before base resources are destroyed.

*   **Code Example**:

```cpp

#include <iostream>

using namespace std;

class A { public: A() { cout << "A "; } ~A() { cout << "~A "; } };

class B : public A { public: B() { cout << "B "; } ~B() { cout << "~B "; } };

class C : public B { public: C() { cout << "C "; } ~C() { cout << "~C "; } };

int main() {

    C obj;

    // Output during creation: A B C&#x20;

    // Output upon destruction: ~C ~B ~A

}

```

---

#### Q6. Why must a Base class Destructor be declared `virtual` when working polymorphically?
*   **Answer**:

    *   If you delete a child object through a parent pointer, a non-virtual parent destructor can prevent the child destructor from running correctly.

    *   **Without `virtual`**: Only `~Base()` executes. Any heap memory or system resources allocated in `Derived` are never cleaned up, resulting in a **memory leak**.

    *   **With `virtual`**: The call uses dynamic dispatch (via VTABLE). `~Derived()` runs first, followed automatically by `~Base()`.

*   **Code Demonstration**:

```cpp

#include <iostream>

using namespace std;

class Base {

public:

    virtual ~Base() { // Crucial virtual keyword!

        cout << "Base Destructor\n\n> **How to use this guide:** You do not need to know every advanced term before starting. Read each answer slowly, run the code examples, and change small things to see what happens. A *class* is a blueprint; an *object* is something made from that blueprint. A *member* is a variable or function inside a class. A *base class* is a parent class, and a *derived class* is a child class.\n\n> **Note:** VTABLE/VPTR details describe a common way compilers implement virtual functions. They are useful for interviews, but the C++ language does not require every compiler to use exactly the same memory layout.\n\n";

    }

};

class Derived : public Base {

    int* buffer;

public:

    Derived() { buffer = new int[50]; }

    ~Derived() override {

        delete[] buffer;

        cout << "Derived Destructor (Memory Freed)\n";

    }

};

int main() {

    Base* ptr = new Derived();

    delete ptr; // Safely calls ~Derived(), then ~Base()

    return 0;

}

```

---

#### Q7. Can a Constructor be `virtual` in C++? Why or why not?
*   **Answer**:

    *   **No**. A constructor cannot be `virtual`.

    *   **Reason 1**: To invoke a virtual function, an object must already have a populated Virtual Pointer (`vptr`) pointing to the Virtual Table (`vtable`). The `vptr` is initialized inside the constructor. An object cannot look up a virtual table before its constructor has run.

    *   **Reason 2**: The constructor requires knowing the exact concrete type being instantiated at compile time to allocate correct memory.

    *   **(Note: The "Virtual Copy Constructor" idiom can be achieved via a custom `virtual Base* clone() const` method).**

---

#### Q8. Can a Constructor be declared `private`? Where is this used?
*   **Answer**:

    *   **Yes**. When a constructor is private, objects of that class cannot be instantiated externally using `new` or stack allocation.

    *   **Use Cases**:

        1. **Singleton Pattern**: Ensures only a single global instance of a class exists.

        2. **Factory Method Pattern**: Forces callers to instantiate objects through controlled static factory functions.

*   **Code Example (Singleton)**:

```cpp

class Singleton {

private:

    Singleton() {} // Private Constructor

public:

    static Singleton& getInstance() {

        static Singleton instance; // Thread-safe in C++11

        return instance;

    }

};

```

---

#### Q9. What is Object Slicing in C++? How can it be prevented?
*   **Answer**:

    *   **Object Slicing** occurs when a derived class object is assigned or passed by value to a base class object (`Base b = derivedObj;`).

    *   The new parent object has room only for parent-class data, so child-specific information is lost in that copy.

    *   **Prevention**: Always pass polymorphic objects by ****pointer (`Base*`)** or **reference (`const Base&`)****.

---

#### Q10. What is a Pure Virtual Destructor? Can it have a function body?
*   **Answer**:

    *   A pure virtual destructor is declared as `virtual ~Base() = 0;` to make a class abstract without needing any other pure virtual methods.

    *   **Crucial Rule**: Unlike regular pure virtual functions, **a pure virtual destructor MUST have a function body defined outside the class**, because derived class destructors always call their base class destructor implicitly. Omitting the body causes a linker error (`undefined reference`).

*   **Code Example**:

```cpp

class AbstractBase {

public:

    virtual ~AbstractBase() = 0; // Pure virtual

};

AbstractBase::~AbstractBase() {} // Must have body definition!

```

---

### Module 2: Inheritance & The Diamond Problem
#### Q11. What are the different types of Inheritance in C++?
*   **Single Inheritance**: Derived class inherits from one base class (`B : public A`).

*   **Multi-level Inheritance**: Class inherits from a derived class (`C : public B`, where `B : public A`).

*   **Multiple Inheritance**: Class inherits from more than one base class (`C : public A, public B`).

*   **Hierarchical Inheritance**: Multiple classes inherit from a single base class (`B : public A`, `C : public A`).

*   **Hybrid (Diamond) Inheritance**: Combination of two or more types (e.g., `A` derived by `B` and `C`, and `D` derived from both `B` and `C`).

---

#### Q12. Explain the Access Specifier rules in C++ Inheritance (Public, Protected, Private).
*   **Summary Table**:

\| Base Member Access | Inherited via `public` | Inherited via `protected` | Inherited via `private` |

\| :--- | :--- | :--- | :--- |

\| **`public`** | `public` in derived | `protected` in derived | `private` in derived |

\| **`protected`** | `protected` in derived | `protected` in derived | `private` in derived |

\| **`private`** | Hidden (Inaccessible) | Hidden (Inaccessible) | Hidden (Inaccessible) |

*   **Rule of thumb**: Derived access specifier acts as a ceiling; members can become more restrictive, never less.

---

#### Q13. In Multiple Inheritance, what determines the constructor execution order?
*   **Answer**:

    *   The execution order of base class constructors is determined **strictly by the order of derivation in the class declaration**, from left to right.

    *   The order in the constructor initialization list is completely ignored by the compiler.

*   **Code Example**:

```cpp

class B { public: B() { cout << "B "; } };

class C { public: C() { cout << "C "; } };

// Left-to-right: B is declared before C

class D : public B, public C {

public:

    D() : C(), B() {} // Order here does not matter! Output is still: B C

};

```

---

#### Q14. Can a derived class call its grandparent's constructor directly in a normal multi-level inheritance chain?
*   **Answer**:

    *   **No**. In standard multi-level inheritance (`A -> B -> C`), class `C` can only call its immediate base class `B`'s constructor.

    *   `B` is responsible for calling `A`'s constructor. Trying `C() : A() {}` produces a compile-time error.

    *   **Exception**: If `A` is inherited as a **`virtual` base class**, then the most derived class (`C` or `D`) is directly responsible for initializing `A`.

---

#### Q15. What is the Diamond Problem in C++? Why does it occur?
*   **Answer**:

    *   This problem appears when `D` inherits from `B` and `C`, and both `B` and `C` inherit from `A`.

    *   `D` ends up containing **two separate instances** of `A` (one via `B`, one via `C`).

    *   **Consequences**:

        1. **Ambiguity**: Accessing `objD.varA` causes compilation errors because the compiler cannot determine whether to use `B::varA` or `C::varA`.

        2. **Memory Bloat**: Duplicated base class state.

```

       A

      / \\

     B   C

      \ /

       D  <-- Contains two copies of A!

```

---

#### Q16. How does Virtual Inheritance resolve the Diamond Problem? Write the exact code.
*   **Answer**:

    *   By inheriting from `A` using the `virtual` keyword (`class B : virtual public A` and `class C : virtual public A`), C++ ensures that only **one single shared instance** of `A` is created inside `D`.

    *   The most derived class `D` initializes `A` directly.

*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class A {

public:

    A() { cout << "A "; }

};

class B : virtual public A {

public:

    B() { cout << "B "; }

};

class C : virtual public A {

public:

    C() { cout << "C "; }

};

class D : public B, public C {

public:

    D() : A(), B(), C() { cout << "D "; }

};

int main() {

    D obj;

    // Output: A B C D (A is constructed only ONCE!)

    return 0;

}

```

---

#### Q17. How does the compiler manage memory layout for Virtual Base Classes?
*   **Answer**:

    *   When virtual inheritance is used, the compiler inserts a hidden pointer called **`vptr_bptr`** (Virtual Base Pointer) or entries in the virtual table pointing to a **Virtual Base Table (VBTABLE)**.

    *   Instead of embedding base `A` directly at fixed offsets inside `B` and `C`, subclasses store an offset pointing to the single shared `A` subobject placed at the end of the object memory layout.

---

#### Q18. What is the difference between Aggregation, Composition, and Inheritance ("IS-A" vs "HAS-A")?
*   **Inheritance ("IS-A")**: A `Car` is a `Vehicle`. Tight coupling; subclasses inherit public interfaces and internal structure.

*   **Composition ("HAS-A", Strong Ownership)**: A `Car` has an `Engine`. The life-cycle of `Engine` is bound to `Car`. If `Car` is destroyed, `Engine` is destroyed.

*   **Aggregation ("HAS-A", Weak Ownership)**: A `Department` has `Professors`. Professors exist independently of the department. Destroying `Department` does not destroy `Professor`.

---

### Module 3: Polymorphism, VTABLE & Tricky Edge Cases
#### Q19. What is the difference between Compile-time and Run-time Polymorphism?
*   **Compile-time (Static Binding / Early Binding)**:

    *   The compiler decides which function to call before the program runs.

    *   Implemented via **Function Overloading**, **Operator Overloading**, and **Templates**.

    *   Faster execution; zero runtime overhead.

*   **Run-time (Dynamic Binding / Late Binding)**:

    *   The program chooses the function while running, based on the object's actual type.

    *   Implemented via **Virtual Functions** and **Base class pointers/references**.

    *   Introduces small overhead (pointer dereference via VTABLE).

---

#### Q20. Why can't functions in C++ be overloaded solely by their return types?
*   **Answer**:

    *   When a function is called, the caller is not required to assign or store the returned value (e.g., `calculate();` as a standalone statement).

    *   In such cases, the compiler cannot deduce which version to call based on caller context, resulting in call-site ambiguity. C++ function name mangling incorporates parameter types, not return types.

*   **Code Example**:

```cpp

// Compilation Error: ambiguous declaration!

int getValue() { return 10; }

string getValue() { return "OOP"; }

int main() {

    getValue(); // Compiler has no way to choose!

}

```

---

#### Q21. How do you implement Operator Overloading in C++? Show an example with complex numbers.
*   **Answer**:

    *   Operator overloading lets you define what an operator such as `+` means for your own class. For example, `c1 + c2` can add the real parts and imaginary parts of two complex numbers.

*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class Complex {

private:

    int real, imag;

public:

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading '+' operator

    Complex operator+(const Complex &other) {

        return Complex(this->real + other.real, this->imag + other.imag);

    }

    void display() const {

        cout << real << " + i" << imag << endl;

    }

};

int main() {

    Complex c1(3, 5), c2(2, 4);

    Complex c3 = c1 + c2; // Evaluates to c1.operator+(c2)

    c3.display();         // Output: 5 + i9

    return 0;

}

```

---

#### Q22. Which operators CANNOT be overloaded in C++?
*   **Answer**:

    The following operators cannot be overloaded in C++:

    1. Scope Resolution Operator (`::`)

    2. Member Access / Dot Operator (`.`)

    3. Pointer-to-member Operator (`.*`)

    4. Ternary / Conditional Operator (`?:`)

    5. `sizeof` Operator

    6. `typeid` Operator

---

#### Q23. What is the difference between Function Overriding and Function Hiding?
*   **Function Overriding**:

    *   Derived class redefines a base class `virtual` function with the **exact same signature and return type**.

    *   Base pointer dynamically dispatches to the derived implementation at runtime.

*   **Function Hiding (Name Hiding)**:

    *   Derived class defines a function with the same name as a base class function, but with **different parameter types** or **without the `virtual` keyword**.

    *   The base class function is hidden from derived scope unless brought in using `using Base::function;`.

*   **Code Example**:

```cpp

class Base {

public:

    virtual void show(int x) { cout << "Base::show\n"; }

};

class Derived : public Base {

public:

    void show() { cout << "Derived::show\n"; } // Hides Base::show(int)!

};

int main() {

    Derived d;

    // d.show(10); // Compile Error: Base::show(int) is hidden!

    d.Base::show(10); // Works

}

```

---

#### Q24. Explain VTABLE and VPTR under the hood. How does C++ dispatch virtual functions?
*   **Answer**:

    *   **VTABLE (Virtual Table)**: A static table constructed per-class at compile time containing function pointers to all virtual functions for that class.

    *   **VPTR (Virtual Pointer)**: A hidden pointer embedded inside every object instance of a class containing at least one virtual function. It points to the class's VTABLE.

    *   **Dispatch Mechanism**:

        1. Base pointer calls `ptr->draw()`.

        2. Program looks up `ptr->vptr`.

        3. Follows `vptr` to the object's runtime class VTABLE.

        4. Fetches the function address for `draw()` from the designated offset and executes it.

```

Object in Memory:            VTABLE for Derived:

+----------------+          +-----------------------+

\|  vptr          | -------->| &Derived::draw        |

\|  data_member   |          | &Derived::calculate   |

+----------------+          +-----------------------+

```

---

#### Q25. What is the size of an empty class? What happens to `sizeof(class)` when a virtual function is added?
*   **Answer**:

    *   **Empty Class Size**: `1 byte`. Guaranteed by the C++ standard so that two distinct object instances have different memory addresses.

    *   **Class with Virtual Function**: Increases to at least the size of a pointer (`4 bytes` on 32-bit systems, `8 bytes` on 64-bit systems) due to the hidden `vptr`.

---

#### Q26. TRICKY INTERVIEW QUESTION: What is the output when a Virtual Function has Default Arguments?
*   **Problem Code**:

```cpp

#include <iostream>

using namespace std;

class Base {

public:

    virtual void show(int x = 10) {

        cout << "Base: " << x << endl;

    }

};

class Derived : public Base {

public:

    void show(int x = 20) override {

        cout << "Derived: " << x << endl;

    }

};

int main() {

    Base* ptr = new Derived();

    ptr->show();

    delete ptr;

    return 0;

}

```

*   **Output**: `Derived: 10`

*   **Explanation**:

    *   **Virtual function dispatch happens at RUNTIME**: Because `show()` is virtual and `ptr` points to `Derived`, `Derived::show()` is called.

    *   **Default argument substitution happens at COMPILE TIME**: The compiler checks the type of the pointer (`Base*`), sees that `Base::show` has default argument `10`, and replaces the call at compile time with `ptr->show(10)`.

    *   **Core Principle**: **Never redefine inherited default arguments in C++!**

---

#### Q27. What are the `override` and `final` specifiers introduced in C++11?
*   **`override`**: Explicitly tells the compiler that the method is intended to override a base class virtual method. If the signature does not match exactly, the compiler generates an error instead of silently hiding the function.

*   **`final`**:

    1. Applied to a method: Prevents derived classes from further overriding it.

    2. Applied to a class (`class Base final {}`): Prevents any class from inheriting from it.

---

#### Q28. Can a `static` member function be `virtual`? Can an `inline` function be `virtual`?
*   **Can `static` be virtual?**: **No**. Static functions are class-level and lack a `this` pointer. They have no object instance to access a `vptr`.

*   **Can `inline` be virtual?**: **Yes, but with caveats**. If invoked via an object (`obj.func()`), the compiler can inline it at compile time. If invoked polymorphically via a base pointer (`ptr->func()`), inlining is disabled and it resolves dynamically via the VTABLE.

---

### Module 4: Abstraction, Interfaces & Design Patterns
#### Q29. What is an Abstract Class versus a Pure Abstract Class (Interface) in C++?
*   **Abstract Class**: A class with at least one Pure Virtual Function (`virtual void f() = 0;`). Can have state (member variables), concrete functions, and constructors. Cannot be directly instantiated.

*   **Interface (Pure Abstract Class)**: A class where **every** member function is pure virtual, with no member variables (except static constants) and a virtual destructor. It defines a pure behavioral contract.

*   **Code Example**:

```cpp

// Pure Abstract Class (Interface)

class Printable {

public:

    virtual void print() = 0;

    virtual void scan() = 0;

    virtual ~Printable() {}

};

class Document : public Printable {

public:

    void print() override { cout << "Printing Document\n"; }

    void scan() override { cout << "Scanning Document\n"; }

};

```

---

#### Q30. Can an Abstract Class have a Constructor? If we cannot instantiate it, why is it needed?
*   **Answer**:

    *   **Yes**. An abstract class can (and often should) have a constructor.

    *   **Purpose**: While external callers cannot write `new AbstractBase()`, derived classes need to initialize protected base class member variables through constructor chaining (`Derived() : AbstractBase(arg) {}`).

---

#### Q31. What happens if a Derived Class fails to implement all Pure Virtual Functions of its Base?
*   **Answer**:

    *   The derived class inherits the unimplemented pure virtual functions and therefore **remains an abstract class itself**.

    *   Attempting to instantiate that derived class triggers a compile-time error: `cannot declare variable 'obj' to be of abstract type`.

---

#### Q32. Can a Pure Virtual Function have an implementation body in C++?
*   **Answer**:

    *   **Yes**. C++ allows pure virtual functions to have a body, but the body must be defined **outside** the class declaration.

    *   Subclasses must still override the function, but they can explicitly invoke the base implementation using `Base::func()`.

*   **Code Example**:

```cpp

class Base {

public:

    virtual void log() = 0;

};

void Base::log() { cout << "Default Base Log\n"; } // Legal!

class Derived : public Base {

public:

    void log() override {

        Base::log(); // Reusing base implementation

        cout << "Derived Log\n";

    }

};

```

---

#### Q33. Implement an Employee Payroll Hierarchy using Abstraction.
*   **Code Implementation**:

```cpp

#include <iostream>

#include <vector>

using namespace std;

class Employee {

public:

    virtual double calculateSalary() = 0;

    virtual string getRole() = 0;

    virtual ~Employee() {}

};

class FullTimeEmployee : public Employee {

    double monthlySalary;

public:

    FullTimeEmployee(double s) : monthlySalary(s) {}

    double calculateSalary() override { return monthlySalary; }

    string getRole() override { return "Full-Time"; }

};

class PartTimeEmployee : public Employee {

    double hourlyRate;

    int hours;

public:

    PartTimeEmployee(double r, int h) : hourlyRate(r), hours(h) {}

    double calculateSalary() override { return hourlyRate * hours; }

    string getRole() override { return "Part-Time"; }

};

int main() {

    vector<Employee*> staff = {

        new FullTimeEmployee(60000),

        new PartTimeEmployee(250, 40)

    };

    for (auto emp : staff) {

        cout << emp->getRole() << " Salary: " << emp->calculateSalary() << endl;

        delete emp;

    }

    return 0;

}

```

---

#### Q34. Implement an extensible Media Player System using Abstraction.
*   **Code Implementation**:

```cpp

#include <iostream>

#include <vector>

using namespace std;

class MediaPlayer {

public:

    virtual void play(const string &filename) = 0;

    virtual ~MediaPlayer() {}

};

class MP3Player : public MediaPlayer {

public:

    void play(const string &f) override { cout << "Playing MP3 Audio: " << f << endl; }

};

class MP4Player : public MediaPlayer {

public:

    void play(const string &f) override { cout << "Playing MP4 Video: " << f << endl; }

};

class VLCPlayer : public MediaPlayer {

public:

    void play(const string &f) override { cout << "Playing VLC Stream: " << f << endl; }

};

```

---

#### Q35. Implement a multi-channel Notification System with Protected Logging.
*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class Notification {

protected:

    void auditLog(const string &msg) {

        cout << "[AUDIT LOG]: Dispatched message -> " << msg << endl;

    }

public:

    virtual void send(const string &msg) = 0;

    virtual ~Notification() {}

};

class EmailNotification : public Notification {

public:

    void send(const string &msg) override {

        cout << "Sending Email: " << msg << endl;

        auditLog(msg);

    }

};

class SMSNotification : public Notification {

public:

    void send(const string &msg) override {

        cout << "Sending SMS: " << msg << endl;

        auditLog(msg);

    }

};

```

---

#### Q36. What is the Strategy Design Pattern? How is it implemented for Payment Processing?
*   **Answer**:

    *   **Strategy Pattern:** Keep different ways of doing a task in separate classes, then choose which one to use while the program runs.

    *   Instead of hardcoding conditional payment branches (`if-else`), a context object (`ShoppingCart`) maintains a pointer to `PaymentStrategy` and delegates execution.

*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

// Strategy Interface

class PaymentStrategy {

public:

    virtual void pay(int amount) = 0;

    virtual ~PaymentStrategy() {}

};

// Concrete Strategies

class CreditCardPayment : public PaymentStrategy {

public:

    void pay(int amount) override { cout << "Paid Rs. " << amount << " via Credit Card.\n"; }

};

class UPIPayment : public PaymentStrategy {

public:

    void pay(int amount) override { cout << "Paid Rs. " << amount << " via UPI.\n"; }

};

// Context Class

class ShoppingCart {

private:

    PaymentStrategy* strategy;

public:

    ShoppingCart() : strategy(nullptr) {}

    void setPaymentStrategy(PaymentStrategy* s) { strategy = s; }

    void checkout(int amount) {

        if (!strategy) {

            cout << "No payment method configured!\n";

            return;

        }

        strategy->pay(amount);

    }

};

int main() {

    ShoppingCart cart;

    UPIPayment upi;

    CreditCardPayment cc;

    cart.setPaymentStrategy(&upi);

    cart.checkout(1500);

    cart.setPaymentStrategy(&cc); // Dynamic strategy swap

    cart.checkout(4500);

    return 0;

}

```

---

### Module 5: Encapsulation, Static Members & Friendship
#### Q37. What is the difference between Encapsulation and Data Hiding?
*   **Encapsulation**: The process of bundling data members and the methods operating on them into a single class entity.

*   **Data Hiding**: Specifically restricting outside direct access to internal state using access specifiers (`private`/`protected`). Data hiding is achieved **through** encapsulation.

---

#### Q38. What is a Friend Function in C++? When should it be used?
*   **Answer**:

    *   A **friend function** is not a class member, but the class gives it permission to access that class's private and protected members.

    *   It is not a member function and does not have a `this` pointer.

    *   **When to use**: Commonly used for operator overloading where the left-hand operand is not a class instance (e.g., `cout << obj`), or for bridging two distinct classes without publicizing their internal state.

*   **Code Example**:

```cpp

class Box {

private:

    int width;

public:

    Box(int w) : width(w) {}

    friend void printWidth(const Box& b); // Friend function declaration

};

void printWidth(const Box& b) {

    cout << "Width: " << b.width << endl; // Direct access to private member

}

```

---

#### Q39. What is a Friend Class? What are its rules regarding Inheritance and Transitivity?
*   **Answer**:

    *   Writing `friend class B;` inside class `A` lets methods of `B` access `A`'s private and protected members.

    *   **Key Rules**:

        1. **Friendship is NOT Mutual**: If `B` is a friend of `A`, `A` is NOT automatically a friend of `B`.

        2. **Friendship is NOT Transitive**: If `B` is a friend of `A`, and `C` is a friend of `B`, `C` is NOT a friend of `A`.

        3. **Friendship is NOT Inherited**: Friends of a base class are not automatically friends of derived classes.

---

#### Q40. How do you declare a member function of another class as a friend? Explain the Forward Declaration requirement.
*   **Answer**:

    *   To declare `ClassB::method()` as a friend inside `ClassA`, the compiler must know about `ClassB` and its method definition beforehand.

    *   **Order required**:

        1. Forward declare `class ClassA;`.

        2. Define `class ClassB` containing the member function prototype.

        3. Define `class ClassA` with `friend void ClassB::method(ClassA&);`.

        4. Implement `ClassB::method` after `ClassA` is fully defined.

*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class Target; // Forward declaration

class Inspector {

public:

    void inspect(Target& t); // Prototype

};

class Target {

private:

    int secret = 777;

public:

    friend void Inspector::inspect(Target& t); // Specific member friend

};

void Inspector::inspect(Target& t) {

    cout << "Inspected private secret: " << t.secret << endl;

}

```

---

#### Q41. Why must Static Data Members be defined outside the class body?
*   **Answer**:

    *   Declaring a static variable inside a class only acts as a **declaration** (informing the compiler of its name and type). It does not allocate storage.

    *   Because static members belong to the class rather than individual instances, memory must be allocated once globally in the data segment.

    *   Defining it outside (`int MyClass::count = 0;`) provides the single definition rule (ODR) storage allocation point.

    *   **(Note: `constexpr` or `inline` static members in C++17+ can be initialized inside the class).**

---

#### Q42. Why can't Static Member Functions access non-static data members or use the `this` pointer?
*   **Answer**:

    *   A static member function belongs to the class itself and can be called as `ClassName::func()` without creating an object.

    *   Because no specific object is attached to the call, there is no `this` pointer passed as an implicit argument, making it impossible to determine which object's instance variable to modify.

---

#### Q43. Design a Centralized Server/Database Connection Manager using Static Members.
*   **Code Implementation**:

```cpp

#include <iostream>

#include <unordered_map>

#include <string>

using namespace std;

class DatabaseConnection {

private:

    int connectionId;

    bool isActive;

    static int nextConnectionId;

    static int activeConnections;

    static unordered_map<int, string> connectionLogs;

public:

    DatabaseConnection() {

        connectionId = ++nextConnectionId;

        isActive = true;

        activeConnections++;

        connectionLogs[connectionId] = "Connection Established";

    }

    ~DatabaseConnection() {

        if (isActive) close();

    }

    void close() {

        if (!isActive) return;

        isActive = false;

        activeConnections--;

        connectionLogs[connectionId] = "Connection Closed";

    }

    static void printMetrics() {

        cout << "\n=== Server Connection Metrics ===" << endl;

        cout << "Total Connections Created : " << nextConnectionId << endl;

        cout << "Active Connections        : " << activeConnections << endl;

        for (const auto &entry : connectionLogs) {

            cout << "Session #" << entry.first << " : " << entry.second << endl;

        }

    }

};

// Static definitions

int DatabaseConnection::nextConnectionId = 0;

int DatabaseConnection::activeConnections = 0;

unordered_map<int, string> DatabaseConnection::connectionLogs;

int main() {

    DatabaseConnection c1;

    DatabaseConnection c2;

    DatabaseConnection c3;

    c2.close();

    DatabaseConnection::printMetrics();

    return 0;

}

```

---

### Module 6: Problem-Solving & Stack-Based Expression Evaluation
#### Q44. Implement a custom Stack from scratch in C++ using an Array with Underflow/Overflow safeguards.
*   **Code Implementation**:

```cpp

#include <iostream>

using namespace std;

class CustomStack {

private:

    static const int CAPACITY = 1000;

    int arr[CAPACITY];

    int topIndex;

public:

    CustomStack() : topIndex(-1) {}

    bool isEmpty() const { return topIndex == -1; }

    bool isFull() const { return topIndex == CAPACITY - 1; }

    void push(int x) {

        if (isFull()) {

            cout << "Stack Overflow!\n";

            return;

        }

        arr[++topIndex] = x;

    }

    int pop() {

        if (isEmpty()) {

            cout << "Stack Underflow!\n";

            return -1;

        }

        return arr[topIndex--];

    }

    int peek() const {

        if (isEmpty()) return -1;

        return arr[topIndex];

    }

};

```

---

#### Q45. What is a Postfix Expression (Reverse Polish Notation), and how do you evaluate it using a Stack?
*   **Answer**:

    *   In postfix notation, the operator comes after the numbers: `2 3 +` means `2 + 3`. A stack helps calculate the result.

    *   **Evaluation Algorithm (Left to Right)**:

        1. Scan expression from left to right.

        2. If character is an operand (digit), push onto stack.

        3. If character is an operator (`+`, `-`, `*`, `/`, `%`):

            - Pop top element as `operand2`.

            - Pop next top element as `operand1`.

            - Compute `result = operand1 <op> operand2`.

            - Push `result` back onto stack.

        4. Final result is the top element of the stack.

*   **Code Implementation**:

```cpp

#include <iostream>

#include <string>

#include <cctype>

#include <stack>

using namespace std;

int evaluatePostfix(const string &expr) {

    stack<int> st;

    for (char ch : expr) {

        if (ch == ' ') continue;

        if (isdigit(ch)) {

            st.push(ch - '0');

        } else {

            int op2 = st.top(); st.pop(); // First pop is second operand

            int op1 = st.top(); st.pop(); // Second pop is first operand

            switch (ch) {

                case '+': st.push(op1 + op2); break;

                case '-': st.push(op1 - op2); break;

                case '*': st.push(op1 * op2); break;

                case '/': st.push(op1 / op2); break;

                case '%': st.push(op1 % op2); break;

            }

        }

    }

    return st.top();

}

int main() {

    string postfix = "23*54*+9-"; // (2*3) + (5*4) - 9 = 6 + 20 - 9 = 17

    cout << "Postfix Evaluation Result: " << evaluatePostfix(postfix) << endl;

    return 0;

}

```

---

#### Q46. What is a Prefix Expression (Polish Notation), and how do you evaluate it using a Stack?
*   **Answer**:

    *   In prefix notation, the operator comes before the numbers: `+ 2 3` means `2 + 3`.

    *   **Evaluation Algorithm (Right to Left)**:

        1. Scan expression from **right to left** (reverse direction).

        2. If character is an operand (digit), push onto stack.

        3. If character is an operator:

            - Pop top element as `operand1` (first pop is `op1`).

            - Pop next top element as `operand2` (second pop is `op2`).

            - Compute `result = operand1 <op> operand2`.

            - Push `result` back onto stack.

        4. Final result is the top of the stack.

*   **Code Implementation**:

```cpp

#include <iostream>

#include <string>

#include <cctype>

#include <stack>

using namespace std;

int evaluatePrefix(const string &prefix) {

    stack<int> st;

    for (int i = (int)prefix.length() - 1; i >= 0; i--) {

        char ch = prefix[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {

            st.push(ch - '0');

        } else {

            int op1 = st.top(); st.pop(); // First pop is operand1

            int op2 = st.top(); st.pop(); // Second pop is operand2

            switch (ch) {

                case '+': st.push(op1 + op2); break;

                case '-': st.push(op1 - op2); break;

                case '*': st.push(op1 * op2); break;

                case '/': st.push(op1 / op2); break;

                case '%': st.push(op1 % op2); break;

            }

        }

    }

    return st.top();

}

int main() {

    string prefix = "*+234"; // ((2 + 3) * 4) = 20

    cout << "Prefix Evaluation Result: " << evaluatePrefix(prefix) << endl;

    return 0;

}

```

---

#### Q47. What is the fundamental operational difference between Postfix and Prefix evaluation algorithms?
*   **Comparison**:

\| Feature | Postfix Evaluation | Prefix Evaluation |

\| :--- | :--- | :--- |

\| **Scan Direction** | Left to Right (`0` to `n-1`) | Right to Left (`n-1` to `0`) |

\| **First Pop** | `operand2` (Right operand) | `operand1` (Left operand) |

\| **Second Pop** | `operand1` (Left operand) | `operand2` (Right operand) |

\| **Operation Form** | `operand1 <op> operand2` | `operand1 <op> operand2` |

---

#### Q48. How do you convert an Infix Expression to Postfix using the Shunting-Yard Algorithm?
*   **Answer**:

    1. Initialize an operator stack and an output string.

    2. Scan infix tokens from left to right:

       - If token is an **operand**, append to output.

       - If token is `'('`, push onto stack.

       - If token is `')'`, pop operators to output until `'('` is encountered; discard `'('`.

       - If token is an **operator** (`+`, `-`, `*`, `/`, `^`):

         - While stack top has higher or equal precedence (taking associativity into account), pop to output.

         - Push current operator onto stack.

    3. Pop all remaining operators from stack to output.

---

#### Q49. What causes Stack Overflow and Stack Underflow, and how do you protect against them in production?
*   **Stack underflow:** Trying to remove or view an item when the stack is empty. Check `isEmpty()` before calling `pop()` or `peek()`.

*   **Stack overflow:** Trying to add an item when a fixed-size stack is already full. It can also mean that too many recursive calls have used up the program's call stack. Check capacity or use a container that can grow.

---

#### Q50. What are the most common C++ OOP interview pitfalls and best practices to keep in mind?
1. **Always declare base class destructors as `virtual`** whenever defining virtual functions.

2. **Follow the Rule of Three/Five**: Custom resource handling demands custom copy and move operations to avoid double-free errors.

3. **Never call virtual functions inside Constructors or Destructors**: During construction/destruction, the object behaves as the base type; dynamic dispatch will not resolve to derived overrides.

4. **Prefer Composition over Inheritance**: Use inheritance for true polymorphism ("IS-A") and composition for capability reuse ("HAS-A").

5. **Always mark overrides with `override`**: Catches signature mismatches at compile time rather than silently introducing hidden functions.

6. **Beware of Virtual Functions with Default Arguments**: Dynamic dispatch selects the function body at runtime, but default parameter values bind statically at compile time.

---

**Authored for Technical SDE & Systems Interview Preparation. All code examples verified for C++14/C++17/C++20 standards.**
