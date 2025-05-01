#include <iostream>

using namespace std;

class Fruit {
public:
    virtual void print_color() const = 0;
    virtual Fruit* clone() const = 0;

    virtual ~Fruit() = default
};

class Apple : public Fruit {
public:
    void print_color() const override {
	    cout << "Red or green!\n";
    }

    Fruit* clone() const override {
        return new Apple(*this);
    }
};

class Orange : public Fruit {
public:
    void print_color() const override {
	   cout << "Orange!\n";
    }

    Fruit* clone() const override {
	    return new Orange(*this);
    }
};

class Lemon : public Fruit {
public:
    size_t sourness;

    Lemon(size_t sourness) : sourness(sourness) {}

    void print_color() const override {
	    cout << "Yellow!\n";
    }

    Fruit* clone() const override {
	    return new Lemon(*this);
    }
};


class FruitStore {
private:
	Fruit** fruits;
	size_t capacity;
	size_t count;
	
	void copy_from(const FruitStore& other);
	void free();
public:
	FruitStore() = default;
	FruitStore(const FruitStore&);
	FruitStore& operator=(const FruitStore&);
	~FruitStore();
	
	void add_apple();
	void add_orange();
	void add_lemon(size_t sourness);
};

void FruitStore::add_apple() {
	// capacity check
	fruits[count++] = new Apple();
}

void FruitStore::add_orange() {
	// capacity check
	fruits[count++] = new Orange();
}

void FruitStore::add_lemon(size_t sourness) {
	// capacity check
	fruits[count++] = new Lemon(sourness);
}

void FruitStore::free() {
	for(size_t i = 0; i < count; ++i) {
		delete fruits[i];
	}
	
	delete[] fruits;
}

void FruitStore::copy_from(const FruitStore& other) {
	fruits = new Fruit * [other.capacity];
	
	for(size_t i = 0; i < other.count; ++i) {
		fruits[i] = other.fruits[u]->clone();
	}
		
	count = other.count;
	capacity = other.capacity;
}

FruitStore::FruitStore(const FruitStore& other) {
	copy_from(other);
}


FruitStore& FruitStore::operator=(const FruitStore&) {
	if (this != &other) {
		free();
		copy_from();
	}

	return *this;
}

FruitStore::~FruitStore() {
	free();
}
