Задача 1: MyVector
Да се реализира клас MyVector<T>. Класът трябва да поддържа следния интерфейс:

MyVector() - конструктор по подразбиране (size = 0, capacity = 8)
MyVector(size_t n) - size = n, capacity = n
MyVector(size_t n, const T& elem) - size_t = n, capacity = n, всеки елемент има стойност elem
push_back(const T& elem), push_back(T&& elem) - добавя елемент в края
pop_back() - премахва последния елемент
insert(size_t idx, const T& elem), insert(size_t idx, T&& elem) - вмъква елемент на подадена позиция
erase(size_t idx) - премахва елемента на подадена позиция
operator[](size_t idx) - достъпва елемент на позиция (константен и неконстантен достъп)
shrink_to_fit() - намалява капацитета до текущия размер и преоразмерява масива
clear() - премахва всички елементи. size = 0, capacity остава непроменено.
front() - връща референция към първия елемент във вектора (константен и неконстантен достъп)
back() - връща референция към последния елемент във вектора (константен и неконстантен достъп)
empty()
size()
capacity()
