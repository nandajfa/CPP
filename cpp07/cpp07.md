### Templates

Templates are a powerful feature that allows you to create generic functions and classes. They enable you to write code that works with various data types without having to repeat the code for each specific type.

There are two main types of templates in C++: function templates and class templates.

* Function Templates:
Function templates allow you to create functions that can be used with different data types. The basic syntax for creating a function template is as follows:

```c++
template <typename T>
T sum(T a, T b) {
    return a + b;
}
```
In this example, the sum function is a function template that takes two parameters of type T and returns the sum of those values. The type T is a template parameter that can be replaced with any valid type at compile time. Thus, we can call this function with different data types, such as int, float, double, or even custom types.

* Class Templates:

Class templates allow you to create generic classes that can work with different data types. The basic syntax for creating a class template is as follows:

```c++
template <typename T>
class List {
private:
    T* elements;
    int size;

public:
    // Class methods...
};
```
In this example, the List class is a class template that stores a list of elements of type T. The type T is a template parameter that can be replaced with any valid type at compile time. Thus, we can create instances of the List class with different data types.

For example, we can create a List<int> to store integers or a List<double> to store floating-point numbers.

```c++
List<int> integerList;
List<double> floatList;
```

Templates in C++ allow you to write flexible and reusable code for different data types, avoiding code duplication. They are widely used in libraries and frameworks to provide generic and flexible abstractions.

When using templates, it's important to remember that the code is generated at compile time for each specific type used, which can increase the size of the final executable. Therefore, it's necessary to find a balance between the flexibility of templates and code efficiency.

[Cpp 07](https://github.com/qingqingqingli/CPP/wiki/Module07)