### Ad-hoc polymorphism / function overload

- Function overloading is a C++ principle, which allows you to define many functions having the same name, but accepting different parameters.

```
class Sample {
public:
	Sample();
	~Sample();

	void bar(char const c) const;
	void bar(int const n) const;
	void bar(float const z) const;
	void bar(Sample const & i) const;
};
int main() {
	Sample sample;
	float f = 3.14;

	sample.bar(5);
	sample.bar('c');
	sample.bar(f);
	sample.bar(sample);
	return 0;
}
```

### Operator overload

Operator overloading enables you to write function members that enable the basic operators to be applied to class objects (source: Beginning C++). To do this, you write a function that redefines each operator that you want to use with your class

Groups operators in C++

Arithmetic operators
Assignment operators
Comparison operators
Logical operators
Bitwise operators

Examples:

```
//Write:
int main()
{
	Tempo t1 = {2, 10};
	Tempo t2 = {1, 30};

	std::cout << t1 + t2;
}
//compiler understands
int main()
{
	Tempo t1 = {2, 10};
	Tempo t2 = {1, 30};

	std::cout << t1.operator+(t2);
}
```

[Operator +](https://github.com/nandajfa/CPP/tree/main/cpp07)
[Operator =](https://github.com/nandajfa/CPP/tree/main/cpp07)

- operator = function.

### Fixed point numbers

Fixed point is a simple yet very powerful way to represent fractional numbers in computer. By reusing all integer arithmetic circuits of a computer, fixed point arithmetic is orders of magnitude faster than floating point arithmetic. This is the reason why it is being used in many game and DSP applications. On the other hand, it lacks the range and precision that floating point number representation offers. You, as a programmer or circuit designer, must do the tradeoff.

### Copy constructor

- If a class has data members that are pointers, you should implement the copy constructor. If you don't, the default copy constructor will copy an object by copying the values of the data members, which means just the addresses for pointers will be copied - not what they point to.
- The result will be two or more objects with members pointing to the same object. A change to an object that is pointed to by a data member of one object will affect all the duplicate objects.
- When you create a copy constructor, the duplicate can be dependent from the original.
