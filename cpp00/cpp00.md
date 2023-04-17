## CPP00

### Namespace

Group symbols and functions containing a semantic relationship in the same set.
You can have two libraries that contain the same name for a given method. With namespace usage you avoid collisions. Allows having the same name and specifying which library that method belongs to.

- Frequently used namespace -> std:: -> finds all standard C++ libraries.

```
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

- CIN -> COUT = standard input and output

```
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

```
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class	Sample
{
public:

	Sample(void); // CPP use the name of the class for constructor
	~Sample(void); // and the name of the class for destructor
};

#endif
```
