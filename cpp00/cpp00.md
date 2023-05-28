## CPP00

### Namespace

Group symbols and functions containing a semantic relationship in the same set.
You can have two libraries that contain the same name for a given method. With namespace usage you avoid collisions. Allows having the same name and specifying which library that method belongs to.

- Frequently used namespace -> std:: -> finds all standard C++ libraries.

```c++
int	gl_var = 1;
int	f(void) { return 2; };

namespace	Foo{
	int	gl_var = 3;
	int	f(void) { return 4; };
}

namespace	Bar{
	int	gl_var = 5;
	int	f(void) { return 6; };
}

namespace	Muf = Bar;

int	main(void){
	printf("gl_var:			[%d]\n", gl_var);
	printf("f():			[%d]\n\n", f());

	//exactly the same as above (global scope)
	printf("::gl_var:		[%d]\n", ::gl_var);
	printf("::f():			[%d]\n\n", ::f());

	printf("Foo::gl_var:		[%d]\n", Foo::gl_var);
	printf("Foo::f():		[%d]\n\n", Foo::f());

	printf("Bar::gl_var:		[%d]\n", Bar::gl_var);
	printf("Bar::f():		[%d]\n\n", Bar::f());

	printf("Muf::gl_var:		[%d]\n", Muf::gl_var);
	printf("Muf::f():		[%d]\n\n", Muf::f());

	return (0);
}

```

### Stdio streams

- Are input and output data streams that allow interacting with files and the system's standard input/output (such as the console). The C++ standard library provides the "cin" object (for standard input) and "cout" object (for standard output).

* CIN -> COUT = standard input and output

```c++
#include <iostream>

int main(void)
{
	char buff[512];

	std::cout << "Hello World!" << std::endl;
	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;
	return 0;
}
```

### Class and instance

- Are structures that allow defining customized data types, with attributes and methods that can be accessed by external code. For example, you can create a "Person" class with attributes such as "name" and "age", and methods such as "setName" and "getAge".

```c++
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class	Sample
{
public:

	Sample(void); // CPP use the name of the class for constructor
	~Sample(void); // and the name of the class for destructor
};

#endif
____________________________________

#include "Sample.class.hpp"

int	main(void)
{
	// the line below instantiate an instance
	// code in constructor will also run (to initialise data for instance)
	Sample	instance;
	return (0);
	// destructor is called when the instance goes out of scope
}
```

### member attributes & functions

- A member function of a class is a function that has its definition or its prototype within the class definition like any other variable. It operates on any object of the class of which it is a member, and has access to all the members of a class for that object. Are functions that belong to a class and can access its attributes. For example, in the "Person" class mentioned above, the "setName" method would be a member function.

- Member attribute is a variable you have in your class, and you may use from an instance.

```c++
class MyClass {
public:
    std::string getValue(std::string fieldName) const; //method - function

private:
    std::string value1 = "foo"; //attributes
    std::string value2 = "bar";
};
```

### this pointer (the self keyword)

- In C++, each object gets its own copy of data members and all objects share a single copy of member functions. To refer to your current instance, use the special instance pointer this.

- One member function only has one copy and is used by multiple objects, how are the proper data members accessed and updated? The compiler supplies an implicit pointer along with the names of the functions as 'this'

```c++
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
std::cout << "Constructor called" << std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    // it is possible to call a function from an instance pointer
    this->bar();
    return;

}
```

### initialization list

- Are initialization lists that allow defining initial values for the attributes of a class more efficiently. For example, in the "Person" class, you can use an initialization list to set the initial value of the "age" attribute in the class constructor.

```c++
class Pessoa {
public:
    Pessoa(std::string nome, int idade)
        : nome(nome), idade(idade) //initialization list
    {
        // constructor
    }

private:
    std::string nome;
    int idade;
};
```

### Static

- is a keyword that indicates that an attribute or method belongs to the class itself, and not to a specific instance of the class. For example, if you have a "Counter" class with a "currentCount" attribute, you can make this attribute static so that it is shared among all instances of the class.

### Const

- Variables declared with const added become constants and cannot be altered by the program.

- `const data members` must be initialized using `initialization list`. No memory is allocated separately for const data member. It is folded in the symbol table due to which we need to initialize it.

- `const data members` is also a copy constructor. We don't need to call the assignment operator which means we are avoiding one extra operation.

- The more your code is `const` and `read only`, the more your code will be robust in the long term.

```c++
public:

	float const pi;
	int qd;

	Sample(float const f);
	~Sample(void);

	// const between ) & ; -> the instance of the class will never be altered
	void bar(void) const;

// it's not assigning f value to pi attribute
// it's initialising pi attribute to the f value
Sample::Sample(float const f) : pi(f), qd(42) {

	std::cout << "Constructor called" << std::endl;
	return;
}

int main() {

	Sample instance(3.14f);

	instance.bar();

	return (0);
}

```

### visibility

The `public` members of a class are accessible from external code to the class, meaning that other parts of the program can access and use them. `Private` members, on the other hand, are only accessible within the class itself.

In other words, "public" members are those that should be used by other parts of the program, while "private" members are those used only within the class itself to help implement its functionalities.

A common example is defining class attributes as private so that access to these attributes is controlled through public methods called "getters" and "setters". This allows you to control how these attributes are accessed and prevents them from being modified improperly.
