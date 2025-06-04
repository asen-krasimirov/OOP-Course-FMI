# Full Seminar Transcript


plan Week04:

-1. questions?

0. struct size пример

struct A {
	char c[30];
	X *x;
}

struct X {
	char c[30];
	int a;
}

ans.: 30 + 2 padding + sizeof(X*) (in 32 bit = 4, in 64 bit = 8) = 30 + 2 + 4 = 36


1. what is oop for?
-> paradigm for *easy* modeling data in the program
-> 		*easy* binding logic together
-> 		*easy* binding logical data together

Примери: Stock, Portfolio, Transaction

2. what is a class? different from struct? (not for now)

Пример: Point, показване, че може да се представи функцията като *външна* и като *член*
-> компилатора свежда функцията до външна

3. член-функции
4. константни член-функции

5. *жизнен цикъл на обект*

6. Конструктор

7. Разлика между default и compiler generated
-> Ако имаме какъвто и да е конструктор разписан -> не се генерира от компилатора
-> Проблем при създаване на масив

8. Деструктор

Пример: Композиране на структури, кой се вика кога

9. Изтриване на масиви в дим памет
delete[] и delete


-----------------------------------------------------------------------------------------------------------------

plan Week05:

-1. questions

0. construction and destruction order примери:

0.1.
struct B;

struct X {
	B b;
};

отг:

B
X
~X
~B

0.2.
struct B;

struct X {
	B *b;
}

отг:

X
~X

0.3.
struct A;
struct B;

struct X {
	A a;
	B b;
}

отг:
A
B
X
~X
~B
~A

0.4.
struct A;
struct B;

struct X {
	A a;
	B b;

	X(A a, B b) : a(a), b(b) {}
	~X();
}

int main() {
	A a;
	B b;

	X x(a, b);
}

отг:
A
B
A
B
X
~X
~A
~B
~A
~B


0.5.
struct X;

X arr* = new X[10];

отг:
10 * X()


1. Копиращ конструктор

2. Оператор =

3. Енкапсулация

4. Абстракция

5. Композиция и агрегация

6. Задача: Employee Payroll System

-----------------------------------------------------------------------------------------------------------------

plan Week06:

-1. questions

0. голяма 4ка преговор- какъв проблем решава

0.1 Копиращ конструктор
0.2 Оператор=

0.3 Задача Book

Book:
  - char *title
  - int pages
  -- display
  -- read/write to file

Bookshelf:
  - Book *
  - capacity
  - count

-----------------------------------------------------------------------------------------------------------------

plan Week07:

-2. Разделна компилация (детайлно разглеждане)

* broken utils.cpp import example

* headers -> used for declaration of logic -> function, classes
    - easier to read classes/logic
    - easier to maintain
    - part of split compilation


* c++ проект/програма -> разделя се на .cpp файлове, които се компилират независимо -> разделна компилация

* Стъпки на компилация на c++ проект:

- Предпроцесиране 
  -> Всички #include, #define и други препроцесорни директиви се обработват, като се разширяват макросите и се включват заглавните файлове в кода. Резултатът е един голям .cpp файл без препроцесорни директиви.
a
-> Всяка предпроцесорна директива (#inlucde, #define) се обработва/разширява (на #inluce се заменя с файла) -> голям cpp файл без директиви

- Компилация
  -> Всеки cpp файл се компилира поотделно -> превръща се в асемблер код (създава се .s файл, съдържащ инструкции за конкретна архитектура)

*** За това се получава грешка при include "utils.cpp" -> И двата .cpp файла се компилират

- Асемблиране
  -> От асемблер кода в машинен код -> генерира се .o (или .obj) файлове -> двоични файлове, съдържащи инструкции, изпълними от процесора

- Свързване (линкване)
  –> Всички обектни файлове (.о файлове) и външни библиотеки се комбинират в един изпълним файл (извършва се от Линкер)

* Разделна компилация ползи
  -> Отделното компилиране на .cpp файловете
  -> По- лесно поддържане на проекта с headers
  -> "Добра ООП cpp практика"

Example: Rectangle


-1. Въпроси?


0. Разделна компилация (имплементация, приложения)

Example: Bus


(anti oop pattern now)

1. приятелски функции
  -> Дава възможност за достъпване на private членове (без getter/setter-и)

cargo_list[i] = other.cargo_list[i];	// cargo_list is private ???

Example: bus_show_capacity function


2. приятелски класове
  -> Даваме достъп на някой клас до всички private членове

Example: bus_garage.cpp


3. предефиниране на операции
  -> Дава ни възможност да предефинираме операторите... +,-,/,...,->,*,()

Приоритет - при изрази с повече от един на брой оператора, определят последователността, в която ще бъдат извършени операциите;

Асоциативност - при изрази с оператори от еднакъв порядък, аналогично дефинират последователността, в която ще бъдат извършени операциите;

Позиция на оператора спярмо аргумента - префиксен, инфиксен и суфиксен

в C++ има два вида оператори:
  - Унарни (на един аргумент)
  - Бинарни (на два аргумента)
  - Тернарен


use cases:
  - I/O -> <<, >>
  - при проверка за еквивалентност -> ==, !=
  - при сравнение/наредба -> <, >, <=, >=

!!! Ако предефинираме оператори, трябва да спазваме return-type на build-in операторите (стойност при +, референция при +=)

примери:

Complex& Complex::operator+=(const Complex& other) {
	real += other.real;
	im += other.im;
	return *this;
}

int main() {
	Complex c(1,3); //1 + 3i;
	Complex c2(10,20) // 10 + 2i;
	c += c2 // now c is 11 + 5i
}

разлика между + и += 


Complex& Complex::operator+=(const Complex& other) {
	real += other.real;
	im += other.im;
	return *this;
}

test1+=test2;
//or equivalently
test1.operator+=(test2);


!!! friend  

Complex operator+(const Complex& lhs, const Complex& rhs){
	complex temp(lhs);        //create a local copy of lhs, calling the copy constructor of complex
	temp+=rhs;                //call to the already defined compound operator +=
	return temp;
}

test1+test2;             //normal expression
//or equivalently        
operator+(test1,test2);  //equivalent expression


next time:

* i/o

* +b1 vs b1+

* къса задача

4. статични елементи?

-----------------------------------------------------------------------------------------------------------------

plan Week08:

-1. Въпроси?

0. Допълнение към предния път:
	- къса задача - my_string example

1. статични елементи- static

	- локални променливи- държат се като глобални
	- функции - обвързват се с файл (не може да се извиква с други файлове)
	- член-функция - обвързва се с класа
	- член-данни - обвързани са с класа

	* Employee example

2. Наследяване

	-> Метод за създаване на нови класове от съществуващи класове.

		Vehicle <- Car	<- Sports Car
				<- Family Car
			<- Bus
			<- Motorcycle

	-> Новият клас съдържа данни и поведение на съществуващия клас.

	- Видове наследяване:
		- Single
		- Multiple
	
	- Термини:
		- Base class
		- Derived class
		- Is-a relationship (Inter is an Employee)
	
	- Inheritance (is-a) vs Composition (has-a)

		Surgeon is-a Doctor
			vs
		Car has-a(n) Engine
Example:

class A {
	//some code
public:
    void f() {
		//some code
	}
	//some code
};

class B : public A {
	//some code
};

int main() {
	B obj;
	obj.f(); // OK!
}

-> Представяне в паметта


-> Типове наследяване в C++:
	- private (по подразбиране)
	- protected
	- public

class A  {
public:
    int x;
protected:
	int y;
private:
    int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A { // 'private' is default for classes
    // x is private
    // y is private
    // z is not accessible from D
};


-> Подаване като параметри на функции.

class A {
public:
	int a;
};

class B : public A {
public:
	int b;
};

void f(A& obj) {
	obj.a++;
}

int main() {
	A obj1;
	B obj2;
	
	f(obj1); //OK!
	f(obj2); //OK!
}



3. Базови и производни класове (Конструктори/Деструктори)

-> Когато се създаде Derived class:
	- Изпълнява се конструктора на Base class-a
	- Изпълнява се конструктора на Derived class-a

-> Когато се изчиства Derived class:
	- Извиква се деструктор на Derived class-а
	- Извиква се деструктор на Base class-а

class Derived : public Base {
    .
    .
    .
public:
Derived(...) : Base(...) {
		.
		.
		.
	}
}


-> Деструкторът на Derived извиква деструктора на Base в края на scope-а си.

Example:
Mage Example


-> Копиране при наследяване

B::B(const B& other) : A(other) { // (copy constructor of A (base class)
   copyFrom(other);
}

B& B::operator=(const B& other) {
   if (this != &other) {
   	A::operator=(other); //operator= of A (base class)
   	free();
   	copyFrom(other);
   }
   return *this;
}

Example:
MovieReview

-----------------------------------------------------------------------------------------------------------------

plan Week09:

0. Въпроси?

1. Множествено наследяване


2. Диамантен проблем/Решение


#include <iostream>

class SuperClass {
public:
    SuperClass() {
        std::cout << "SuperClass default constructor is called\n";
    }
};

class A : public SuperClass {
public:
    A() {
        std::cout << "A default constructor is called\n";
    }
};

class B : public SuperClass {
public:
    B() {
        std::cout << "B default constructor is called\n";
    }
};

class C : public A, public B {
public:
    C() {
        std::cout << "C default constructor is called\n";
    }
};

int main() {
    C obj;
}

Решение: virtual при наследяване, конструкторът по подразбиране на прародителя се извиква по подразбиране, дори ако родителските класове извикват изрично конструктор с параметри. 

3. Задача:
- Figure
- Rook
- Bishop
-> Queen (Rook + Bishop)

- Board

-----------------------------------------------------------------------------------------------------------------

plan Week10:

0. Въпроси?


1. Статично и динамично свързване.

	#include <iostream>

	class Base {
	public: 
	    void f() const  {
	        std::cout << "Base::f()\n";
	    }
	};

	class Derived : public Base {
	public:
	    void f() const {
        	std::cout << "Derived::f()\n";
	    }
	};

	void func(const Base& obj) {
	    obj.f();
	}

	int main() {
	    Derived* bPtr = new Derived();
	    Base* aPtr = bPtr;

	    //Early binding - Compile time
	    func(*aPtr); // Base::f()
	    func(*bPtr); // Base::f()
	}

-> Статично свързване (Static binding/Early binding) - изборът на функцията, която трябва да се изпълни става по време на компилация (Compile time)

-> Динамично свързване (Dynamic binding/Late binding) – изборът на функцията, която трябва да се изпълни става по време на изпълнение на програмата (Run time).

	#include <iostream>

	class Base {
	public:
	    virtual void f() const {
        	std::cout << "Base::f()\n";
	    }
	};

	class Derived : public Base {
	public:
	    void f() const override {
        	std::cout << "Derived::f()\n";
	    }
	};

	int main() {
	    Base* ptrs[2];
	    ptrs[0] = new Base(); //Base pointer to Base class object
	    ptrs[1] = new Derived(); //Base pointer to Derived class object

	    //Dynamic/Late Binding - Runtime
	    ptrs[0]->f(); // Base::f()
	    ptrs[1]->f(); // Derived::f()

  	    Base *ptr = new Derived();
	}

-> Виртуална функция - член-функция, която е декларирана в основен клас (Base class) и е предефинирана от производен клас (Derived class).


2. Виртуални функции.

	-> Достъпват се чрез reference (&) или pointer (*)

	-> Винаги се дефинират в базовия клас, като се предефинират в производния ( не е задължително да се overwrite-ва ). ! Сигнатурата трябва да бъде същата. !

	Забранено: 
		-> не може да бъде static
		-> не може да има virtual constructor

Ключови думи:
	- override 	-> презаписване на virtual функция
	- final		-> указване, че няма да се презаписва повече

Пример:
NumbersFile


3. Виртуални таблици.

	#include <iostream>

	struct A {
	    virtual void f() {
	        std::cout << "A::f()" << std::endl;
	    }

	    virtual void g() {
	        std::cout << "A::g()" << std::endl;
	    }
	};

	struct B : public A {
	    void f() override {
	        std::cout << "B::f()" << std::endl;
	    }
	};

	int main() {
	    A* ptr;         // Base class pointer
	    B b_instance;   // Derived class object

	    ptr = &b_instance;

	    ptr->f(); // Calls B::f() due to dynamic dispatch (virtual table)
	    ptr->g(); // Calls A::g(), since it's not overridden in B

	    return 0;
	}

-> Репрезентация в паметта


4. Полиморфизъм.
	-> Полиморфизмът в C++ позволява обектите да бъдат третирани като инстанции на базовия си тип, като същевременно проявяват поведение, специфично за производните им типове.
	   Това е крайъгълен камък на обектно-ориентираното програмиране и се среща в две основни форми: compile-time polymorphism (статичен) и runtime polymorphism (динамичен).

	4.1. Compile-Time Polymorphism

		a. Function Overloading	

			#include <iostream>
			
			void print(int i) {
			    std::cout << "Integer: " << i << std::endl;
			}
			
			void print(double d) {
			    std::cout << "Double: " << d << std::endl;
			}

			int main() {
			    print(42);     // Calls print(int)
			    print(3.14);   // Calls print(double)
			    return 0;
			}
		

		b. Operator Overloading

		c. Function Templates -> TBA

	4.2. Runtime Polymorphism

	-> ! За да се извикват правилните деструкори задължително деструкторът на базовият клас трябва е деклариран като виртуален !


	#include <iostream>

	class Base {
	public:
	    Base() {
	        std::cout << "Base::Base()\n";
	    }

	    ~Base() {
	        std::cout << "Base::~Base()\n";
	    }

	    // alternatively -> virtual ~Base() = default;
	};

	class Derived : public Base {
	public:
	    Derived() {
	        std::cout << "Derived::Derived()\n";
	    }

	    ~Derived() {
        	std::cout << "Derived::~Derived()\n";
	    }
	};

	int main() {
	    Base* ptr = new Derived();
	    delete ptr; //invokes the destructor of Base only, since ~Base() is not virtual
	}

	-> Една виртуална функция -> Виртуален Деструктор

-----------------------------------------------------------------------------------------------------------------

plan Week11:

0. Въпроси?

1. Абстрактни класове.

	-> pure virtual functions

	class Animal {
	public:
		virtual void sayHello() const = 0;
  
		virtual ~Animal() = default; 
	};

	class Dog : public Animal {
	public:
		void sayHello() const override {
		  std::cout << "Hello, I am a dog!" << endl;
	     	}
	};

	class Cat : public Animal {
	public:
		void sayHello() const override {
	  	  std::cout << "Hello, I am a cat!" << endl;
		}
	};

	class Mouse : public Animal {
	public:
		  void sayHello() const override {
	    	    std::cout << "Hello, I am a mouse!" << endl;
		  }
	};

	struct PrehistoricAnimal : public Animal {};

	int main() {
	  // Animal* pa1 = new Animal(); No! Animal is an abstract class!
	  // Animal* pa2 = new PrehistoricAnimal(); No! PrehistoricAnimal is also an abstract class!

	  Animal** animals = new Animal*[3];

	  animals[0] = new Dog();
	  animals[1] = new Cat();
	  animals[2] = new Mouse();


	  //from base-class pointer
	  animals[0]->sayHello(); // Hello, I am a dog!
	  animals[1]->sayHello(); // Hello, I am a cat!
	  animals[2]->sayHello(); // Hello, I am a mouse!

	  for(size_t i = 0; i < 3; ++i) delete animals[i];
	  delete[] animals;
	}

	
	-> !!! Pure virtual destructor трябва изрично да бъде дефиниран. (explicitly defined)


Interface vs Abstract Classes:
	Интерфейсът няма реализация на нито един от своите методи.Tой може да се разглежда като колекция от декларации на методи.	
	В C++ интерфейсът може да бъде симулиран, като всички методи се правят като чисто виртуални.


2. Колекции от обекти в полиморфна йерархия.

Пример:
FruitStore

	2.1. Триене
	2.2. Kопиране


-----------------------------------------------------------------------------------------------------------------

plan Week12:

0. Въпроси ?

1. Разпознаване и прихващане

Приме:
GameObject


2. Move semantics

int x;

int& getRef() {
	return x;
}

int main() {
	getRef() = 4;  // Okay, getRef() is an lvalue - returns a reference to the global variable x
	return 0;
}


lvalue - това са изрази, които притежават някакъв адрес в паметта, например променливи, обекти, функции, връщащи референция към някакъв тип и т.н.

rvalue - това са изрази, които не са lvalue


- Move конструктор 
	
	Student::Student(Student&& other) noexcept : name(other.name), age(other.age) {
		other.name = nullptr;   // Leaves toMove in a state that further destruction will do no harm!
	}

- Move Assignment оператор

	Person& operator=(Person&& other) noexcept {
		if(this != &other) {
			free();	// Free the resources associated with this

			name = other.name;
			age = other.age;

			other.name = nullptr;  // put other in a state where deleting won`t cause problems in further uses of this
		}

		return *this;
	}


3. Exception Handling

-> Начин за сигнализиране при възникнала грешка.


-> Един от най-разпространените начини за обработка на потенциални грешки е чрез връщане на специфични кодове, но не винаги има подходяща стойност, която можем да върнем.


-> Обработката на изключения (exception handling) предоставя механизъм за отделяне на логиката за обработване на грешки от логиката на останалия код.


exception - сигнал, че е възникнал някакъв проблем

синтаксис: throw <object>


	void f() {
    		throw 3;
	}


	int main() {

		if (true) {
			f();
		}
	}

…

	void f(int *arr) {
		if (arr == nullptr) {
			throw 1;
		}
		/// code
	}

	int main() {
		f(nullptr);
		// vs
		f(new int[10]);
	}


4. try, catch, throw mechanism in C++.

	class A {};

	void f() {
	    throw 3;
	}

	int main() {
      		 try {
	           f(); // проблемен код
	       }
	       catch (int n) {
	           // обработване на хвърлен int
	           cout << n << endl;
	       }
	       catch (const A& a) {
	           // задължително по референция
        	   // обработване на хвърлена инстанция на клас A
	           cout << "A obj;" << endl;
	       }
	       catch (...) {

	       }
	
	}


5. Stack unwinding
	
	-> При stack unwinding се унищожават обектите от всяка стек рамка, което води до извикване на деструктури.

	-> 2 exception-а -> terminate()

	-> в деструкторите НИКОГА НЕ хвърляме грешки

	void g() {
	    X x;
	    throw 3;
	}

	void f() {
	    A obj1;
	    B obj2;
	    g();
	    C obj3;
	}

	int main() {
	    try {
	        f(); // ~X() ~B() ~A()
	    }
	    catch (int n) {

	    }
	    catch (...) {

	    }    
	}

Possible problems:

	class X {
	    A a;
	    B b;
	    char* first_name;
	    char* last_name;

	public:
	    X(...) : a(...), b(...) {
	        first_name = new char[...]; // if it doesn't allocate => doesn't matter
	        strcpy(...);
	        try {
	            last_name = new char[...]; // if it fails to allocate => we have to delete first_name
	            strcpy(...);
	        }
        	catch(std::std::bad_alloc& ex) {
	            delete[] first_name;
	        }
	    }
}

6. Custom exceptions


Видове грешки:

	std::bad_alloc - грешка при заделяне на памет
	std::bad_cast - грешка при кастване
	std::runtime_error - грешка по време на изпълнение
	std::logic_error - грешка, която нарушава условията, които трябва да са изпълнени и може да бъде предотвратена


Пример за standard exception:

	#include <iostream>
	#include <exception>

	using namespace std;

	void f(int n) {
		if (n < 0) {
			throw invalid_argument("Number should be positive!");
		}
	}

	int main() {
		try {
			f(-1);
		}
		catch (invalid_argument& e) {
			cout << e.what() << endl; // съобщението на грешката
		}
		catch (logic_error& e) {

		}
		catch (exception& e) {

		}
	}

Пример за custom exception:

	#include <iostream>
	#include <exception>

	using namespace std;

	// Define custom exception
	class MyException : public exception {
		// my_string message;
	public:
    	    explicit MyException(const my_string& msg) : message(msg) {}
    
	    const char* what() const noexcept override {
	        return "My custom exception occurred!";
	    }
	};

	int main() {
	    try {
	        throw MyException();
	    } catch (const exception& e) {
	        std::cout << e.what() << std::endl;
	    }
	    return 0;
	}

7. Примерна задача
ProbeExample


-----------------------------------------------------------------------------------------------------------------

plan Week13:


-1. Въпроси?


0. Контролно 3	(23.05.25)

-> 2 групи
	-> нечетни:	321 от 09:15 - 10:45
	-> четни:	TBA от 09:15 - 10:45


1. Шаблони / Теймплейти

Функция/клас, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас

	#include <iostream>
	using namespace std;

	template <class T>
	T my_sum(const T& a, const T& b) {
    		return a + b;
	}

	int main() {
    		int a = 4;
    		int b = 9;
    		cout << my_sum<int>(a, b) << endl;

    		double c = 3.14;
	    	double d = 4.5;
		cout << my_sum<double>(c, d) << endl;
	
	    	return 0;
	}

Компилаторът генерира т. нар. шаблонна функция (при sum<int>(...) и при sum<double>(...)), като замества параметрите на шаблона с типовете на съответните конкретни параметри.


2. Темплейтна специализация

Различно поведение на темплейтния клас/функция за определени типове

#include <iostream>

using namespace std;

template <typename T>
class Test {
	T data;

public:
	Test();
};

template <>
class Test<char> {
	char data;
public:
	Test();
};

template<typename T>
Test<T>::Test() {
	cout << "T implementation..." << endl;
}

Test<char>::Test() {
	cout << "char implementation..." << endl;
}


int main() {
	Test<int> t1;

	Test<char> t2;
}


-> Ако се изпусне подаването на тип -> изпълнява се тази имплементация, която съвпада с типа

print<>(...) 	-> валидно

print(...) 	-> валидно


print<>(new char[2], 2) -> вика се char имплементацията

print(new int[2], 2)	-> вика се int имплементацията

3. Теймплейтни класове
	
	struct Test

4. Необходими функции

	class A {};

	template <typename T>
	struct Test {
		T surprise;

		void func() {
			int res = 1 + surprise;
		}
	};

	int main() {
		Test<A> t;

		return 0;
	}

	-> Необходимо е класа на типа на surprise да имплементира operator+



	struct Test {
		void func() {}
	}

	template<typename T>
	void f2(T& t) {
		t.func1();
	}

	template<>
	void f1(Test& t) {
		t.func();
	}

	int main() {
		Test t;
		f1<Test>(t); // ok
		f2<Test>(t); // compile error
	}

	-> Необходимо е произволния тип Т да има функцията func1() -> не можем да си го подсигурим
	-> Можем да си го подсигурим само с теймплейтна спецификация


5. Конкретен тип може да се слага

	template <typename T, const size_t capacity>
	...

6. Примери за шаблони в stl
	- Функции
		std::sort
		std::swap
	- Структури
		std::vector
		std::queue
		std::stack
		std::optional
		std::pair
		
		smart pointers - unique_ptr, shared_ptr, weak_ptr


7. h/cpp files problem -> hpp solution

Пример:
my_queue	(goro)

vector refactor to hpp

pair

heterogenic container ?


-----------------------------------------------------------------------------------------------------------------

plan Week14:


-1. Въпроси?

0. quick my_vector 


1. Умни указатели в C++
	-> Умен указател е обвиващ клас за обикновен указател, който менажира автоматично паметта на обекта, към който сочи.

	-> Цел: Да не използваме директно new и delete, с цел да не пропуснем да изтрием даден ресурс.

	-> При създаване с new, умният указател поема собствеността над обекта. При изтриване — автоматично извиква деструктора му.


2. unique_ptr
	-> std::unique_ptr - точно един указател за точно един ресурс

	-> пример:

	#include <iostream>
	class A {
	public:
	    A(int a, bool b) { /*...*/ }
	    ~A() { /*...*/ }
	};

	int main() {
	    std::unique_ptr<A> up = std::make_unique<A>(2, true); // автоматично извиква конструктора A(2, true)
	} // При изход от main() се извиква ~A()


	-> имплементация: my_unique_ptr

	-> имплементация: make_my_unique_ptr

typename... Args 	    ->	Accept any number of template parameters
Args&&... args	            ->	Accept any number of arguments, preserving value category
std::forward<Args>(args)... ->	Forward the arguments without losing efficiency


Задача: ResourceManager



3. shared_ptr
	- std::shared_ptr - пази указател към обект и брояч колко указатели са насочени към обекта
	
	- пример:
	
	using namespace std;

	#include <iostream>

	class A {
	public:
		A(int x, int y) { cout << "A(" << x << "," << y << ")" << endl; }
		void f() { cout << "A::f()" << endl; }
	};

	int main() {
		shared_ptr<A> sp = make_shared<A>(2, 3);
		shared_ptr<A> sp2 = sp;
		shared_ptr<A> sp3 = sp;

		sp2.reset();
		sp3.reset();
		//sp.reset();

		if (sp) {
			sp->f();
		}
		else {
			cout << "sp is null. Cannot call f()." << endl;
		}
	}


Пример: main_shared_example.cpp


4. Има много начини да се допусне грешка с умни указатели...

	-> credit: Serhan


5. weak_ptr
	- std::weak_ptr


-----------------------------------------------------------------------------------------------------------------

plan Week15:

0. Въпроси


1. Design patterns

	- Стандартни решения на често срещани проблеми в софтуерния дизайн.

	- Те не са специфичен код, който да може да copy paste-нете във вашия проект, а са концепция по какъв начин да решите даден проблем.

	- Всеки design pattern е шаблон, по който да се реши различен проблем.


2. Singleton

	-> Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.


	-> Real World Analogy: Government

	-> Пример задача- ConfigurationManager


3. Builder

	-> Builder is a creational design pattern that lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.

	-> Real World Analogy: Car Building

	-> Пример задача- StringBuilder


4. Factory

	-> Separates the logic of creation from the main class.
	
	-> make_unique_ptr, clone method


5. STL in OOP

	-> STL stands for the Standard Template Library

	-> It’s a powerful collection of template-based classes and functions that provide generic implementations of data structures and algorithms.

	-> Containers
		- vector, list, deque
		- set, map
		- unordered_map, unordered_set
		- stack, queue, priority_queue
	
	-> Algorithms
		std::sort(vec.begin(), vec.end());
		std::find(vec.begin(), vec.end(), 42);
		std::count(vec.begin(), vec.end(), 100); 
		
		Over 60 algorithms, including:

			Searching

			Sorting

			Merging

			Modifying


	-> Iterators



6. std::vector

7. std::string

8. std::map


#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
    map<string, int> age_map;

    age_map["Alice"] = 30;
    age_map["Bob"] = 25;
    age_map.insert({ "Charlie", 20 });

    cout << "Alice is " << age_map["Alice"] << " years old." << endl;

    for (const auto& pair : age_map) {
        cout << pair.first << ": " << pair.second << endl;
    }

    if (age_map.find("Diana") == age_map.end()) {
        cout << "Diana not found" << endl;
    }

    return 0;
}












