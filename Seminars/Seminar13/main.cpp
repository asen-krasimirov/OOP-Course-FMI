#include <iostream>

#include "my_queue.hpp"

using namespace std;


int main() {
	my_queue<int> q1;

	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << q1.peek() << endl;

	q1.pop();
	q1.pop();
	q1.pop();

	q1.push(4);

	q1.pop();

	try {
		cout << q1.peek() << endl;
	} catch (std::exception& e) {
		cout << e.what() << endl;
	}
}

