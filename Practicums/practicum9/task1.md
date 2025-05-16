## Задача 1
Реализирайте темплейтна функция sort. 
Ако темплейтния аргумент са числа от тип: 
- `int` - bubble sort
- `double` - selection sort
- `unsigned int` - insertion sort

## Задача 2: MyPair
Да се реализира шаблонен клас ```MyPair<T,D>``` със следните функционалности:

публични полета:
```c++
        Pair(const T& first, const D& second);
	Pair(T&& first, D&& second);
	Pair(const T& first, D&& second);
	Pair(T&& first, const D& second);

	T& getFirst();
	D& getSecond();
	const T& getFirst() const;
	const D& getSecond() const;

	void setFirst(const T& newValue);
	void setFirst(T&& newValue);
	void setSecond(const D& newValue);
	void setSecond(D&& newValue);
```

Допълнителни функции:
- оператор ==
- оператор !=
- оператор <


## Задача 3
Да се реализира клас `Optional<T>`. Класът представлява обект, който може да има стойност, от тип `T`, а може и да няма.
Класът трябва да поддържа следния интерфейс:

* `operator*()`         - Връща стойността.
* `has_value()`         - Казва дали имаме стойност.
* `get_value()`         - Връща стойността
* `set_value(const T&)` - Сет-ваме стойността на Optional
* `reset()`             - Унищожава стойността ако има такава.

## Задача 4: MyStack
Да се реализира шаблонен клас ```MyStack<T>```. Класът да поддържа следните функционалности:
- void push(const T& elem)
- void push(T&& elem)
- void pop()
- const T& top() const
- bool empty() const
- size_t size

## Задача 5: MyVector
Да се реализира клас ```MyVector<T>```. Класът трябва да поддържа следния интерфейс:
- MyVector<T>() - конструктор по подразбиране (size = 0, capacity = 8)
- MyVector<T>(size_t n) - size = n, capacity = n
- MyVector<T>(size_t n, const T& elem) - size_t = n, capacity = n, всеки елемент има стойност elem
- push_back(const T& elem), push_back(T&& elem) - добавя елемент в края
- pop_back() - премахва последния елемент
- insert(size_t idx, const T& elem), insert(size_t idx, T&& elem) - вмъква елемент на подадена позиция
- erase(size_t idx) - премахва елемента на подадена позиция
- operator[](size_t idx) - достъпва елемент на позиция (константен и неконстантен достъп)
- shrink_to_fit() - намалява капацитета до текущия размер и преоразмерява масива
- clear() - премахва всички елементи. size = 0, capacity остава непроменено.
- front() - връща референция към първия елемент във вектора (константен и неконстантен достъп)
- back() - връща референция към последния елемент във вектора (константен и неконстантен достъп)
- empty()
- size()
- capacity()

