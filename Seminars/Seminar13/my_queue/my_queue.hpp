#pragma once

#include "exceptions.h"

using namespace std;

template <typename T>
class my_queue {
	static const short INITIAL_CAPACITY = 4;
	static const short RESIZE_COEF = 2;

	T* data;
	size_t size;
	size_t capacity;

	size_t get, put = 0;

	void resize();

	void increment_index_pointer(size_t& index_pointer);

	void copy_from(const my_queue<T>& other);
	void free();
public:
	my_queue();
	my_queue(const my_queue<T>& other);
	my_queue<T>& operator=(const my_queue<T>& other);
	~my_queue();

	void push(const T& value);

	void pop();

	const T& peek() const;

	bool is_empty() const;
};

template<typename T>
void my_queue<T>::resize() {
	T* new_data = new T[capacity * RESIZE_COEF];

	for (size_t i = 0; i < size; i++) {
		new_data[i] = data[get];
		increment_index_pointer(get);
	}

	capacity *= RESIZE_COEF;
	delete[] data;
	data = new_data;
	get = 0;
	put = size;
}

template<typename T>
void my_queue<T>::increment_index_pointer(size_t& index_pointer) {
	index_pointer = (index_pointer + 1) % capacity;
}

template<typename T>
inline void my_queue<T>::copy_from(const my_queue<T>& other) {
	get = other.get;
	put = other.put;
	capacity = other.capacity;
	size = other.size;

	data = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

template<typename T>
inline void my_queue<T>::free() {
	delete[] data;
}

template<typename T>
my_queue<T>::my_queue() : data(new T[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY), get(0), put(0) {
}

template<typename T>
my_queue<T>::my_queue(const my_queue<T>& other) {
	copy_from(other);
}

template<typename T>
my_queue<T>& my_queue<T>::operator=(const my_queue<T>& other) {
	if (this != &other) {
		free();
		copy_from(other);
	}

	return *this;
}

template<typename T>
my_queue<T>::~my_queue() {
	free();
}

template<typename T>
void my_queue<T>::push(const T& value) {
	if (size == capacity) {
		resize();
	}

	data[put] = value;
	increment_index_pointer(put);
	size++;
}

template<typename T>
inline void my_queue<T>::pop() {
	if (is_empty()) {
		throw queue_is_empty_exception();
	}
	
	increment_index_pointer(get);
	size--;
}

template<typename T>
const T& my_queue<T>::peek() const {
	if (is_empty()) {
		throw queue_is_empty_exception();
	}

	return data[get];
}

template<typename T>
bool my_queue<T>::is_empty() const {
	return size == 0;
}

