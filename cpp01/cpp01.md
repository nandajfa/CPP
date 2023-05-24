### New and delete

- new() and delete() use malloc() and free() in reality, but they also call the constructor and destructor in an appropriate way.
- new() does not take parameters. So need to think of ways to initialise values.

```
int main()
{
	Student		bob = Student("bfubar");
	Student*	jim = new Student("jfubar");

	// Do some stuff here

	delete jim; // jim is destroyed

	return (0); // bob is destroyed
}
```

### Stack vs heap memory

Both of these memories locate in the RAM. The way the memory will be assigned is different

Stack

- Has predefined size (around 2GB).
- When we want to use stack memory, the stack pointer moves and allocate the size of the memory that we want, and return the stack pointer. So the values we assign on stack will be close to each other and be assigned backwards. A stack memory allocation is one CPU instruction and very fast.
- Once the scope in which you allocated that stack memory ends, all the memory allocated in the stack will be reclaimed.
- Stack overflow happens when all the memory in the stack has been allocated, in which case further allocations begin overflowing into other sections of memory.
- If you can allocate on the stack, choose stack.

Heap

- Has a predefined size but it can grow
- Use new() keyword to allocate on the heap
- Sequential memory requests may not result in sequential memory addresses being allocated
- The heap allocated memory needs to be manually freed
- Dynamically allocated memory must be accessed through a pointer. Dereferencing a pointer is slower than accessing a variable directly

### Pointers

- Pointers are extremely important for managing and manipulating memory.

- A pointer is an integer that stores a memory address. It is the address of where that specific memory is.

- The types of that pointer do not matter. It only indicates the type of data that's presumably holding. It's something we write to make our lives easier syntatically. Type does not change what a pointer is.

- Pointing to an invalid memory address (like 0) is perfectly fine for pointer.

- When putting & before a variable, we are asking the address of that variable.

- Dereferencing (\*ptr) means accessing the data. In this way, you can write to or read from the data.

- Pointers themselves are also variables and stored in memory.

### References

- References are aliases for existing variables. It is a pointer that is constant and always dereferenced and never void.

Reference

- A way for us to reference an existing variable. But pointer can be pointing to a non-existing address
- References are not new variables. they don't really occupy memory or have storage
- int& ref = a; & is part of the type. We actually created an alias
- When you pass a value to a function, you are passing a copy of the value. For the destination function to change the value, you need to pass the memory address of that variable (using a reference or a pointer).
- `*value++` Because of the order of operation, it will increment first and then dereference it. What's correct is to dereference first and increment it later - `(*value)++`
- If you can, use reference and it will make the source code looks cleaner.
- Once you define a reference, you can't change what a reference is.

### References vs. pointer

- You can't change where the reference is pointing to. It will always point to the same variable.
- You can't create a reference and let it point to nothing (uninitialised reference). Because it is constant, you can't point to something else later. But a reference can't point to nothing.
- Advantage: when you have a reference, you are sure that it's pointing to something.
- Reference is like a dereferenced pointer. So you don't need to add any symbol to access it.

* References are complimentary to pointers but they don't replace pointers. However, you can't have a reference and not initialise it to something. In comparison, using a pointer, you can point it to something that does not exist in the beginning, and change what it points to later.

* Pointers and references are essentially the same thing, regarding how the computer will do with them. Pointers are more flexible than references. If something should always exist and never change, use a references. But if it should not always exist and can change, use a pointer.

```
int	main()
{
	int		numberOfBalls = 42;

	int*	ballsPtr = &numberOfBalls;
	int&	ballsRef = numberOfBalls;
	// the reference will be pointing to the variable
	// from this point on, you can't change what your reference is pointing to

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return (0);
}

// Result
// 42 42 42
// 21
// 84
```

### File streams

- Streams that interact with files. There are three types of stream objects for working with files: ifstream, ofstream, and fstream.

- These classes have istream, ostream, and iostream as base classes, respectively.
- An istream object represents a file input stream so you can only read it.
- An ofstream object represents a file output stream that you can only write to it.
- An fstream is a file stream that you can read or write.

```
#include <iostream>
#include <fstream>

int main()
{
	//ifstream: input file stream
	std::ifstream	ifs("numbers");
	unsigned int	dst;
	unsigned int	dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	//-------------------------
	//ofstream: output file stream
	std::ofstream	ofs("test.out");
	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
	return (0);
}
```

### Resources

[sstream](https://cplusplus.com/reference/sstream/)
[fstream](https://cplusplus.com/reference/fstream/)
[iostream](https://cplusplus.com/reference/iostream/)
[Stack vs Heap Memory in C++](https://www.youtube.com/watch?v=wJ1L2nSIV1s)
[Stack and heap](https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/)
[const Keyword in C++](https://www.studytonight.com/cpp/const-keyword.php#)
