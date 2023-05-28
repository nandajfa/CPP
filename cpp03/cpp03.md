### inheritance introduction

- Inheritance is the means by which you can create new classes by reusing and expanding on existing class definitions.
- One class is derived from another by adding extra properties, by specialization and making the new class a specialized version of the more general class.

```
// base class
class Animal {
private:
	int _numberOfLegs;

public:
	Animal();
	Animal(Animal const &);
	Animal& operator=(Animal const &);
	~Animal();

	void run(int distance);
	void call();
	void eat(std::string const & what);
	void walk(int distance);
};

// It means that Cat is an animal
// public inheritance
class Cat : public Animal {

public:
	Cat();
	Cat(Cat const &);
	Cat& operator=(Cat const &);
	~Cat();

	void scornSomeone(std::string const & target);

};

class Pony : public Animal {

public:
	Pony();
	Pony(Pony const &);
	Pony& operator=(Pony const &);
	~Pony();

	void doMagic(std::string const & target);
	void run(int distance); // it will replace the animal function
};
```

- [inheritance](https://www.youtube.com/watch?v=TLQzg0b-AY4)<br>

### multiple inheritance

- A derived class can have as many direct base classes as an application requires. This is referred to as multiple inheritance as opposed to single inheritance, in which a single base class is used. Multiple inheritance is used much less frequently than single inheritance and in best avoided as much as possible.
  <br>

```
class CerealPack : public Carton, public Contents
{
	// details of the class...
};
```

- [multiple inheritance](https://www.youtube.com/watch?v=AeVSaQ8HLMU)

### The diamond problem

- The diamond problem occurs when two superclasses of a class have a common base class. For example, in the following diagram, the TA class gets two copies of all attributes of Person class, this causes ambiguities.

- The solution to this problem is ‘virtual’ keyword. We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class.

* How does virtual solve the diamond problem? Virtual inheritance means that there will be only 1 instance of the base A class not 2. [source](https://stackoverflow.com/questions/2659116/how-does-virtual-inheritance-solve-the-diamond-multiple-inheritance-ambiguit)
