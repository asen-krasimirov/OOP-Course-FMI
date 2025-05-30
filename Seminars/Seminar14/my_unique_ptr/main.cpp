#include <iostream>

#include "my_unique_ptr.hpp"

using namespace std;

struct Test {
    int x;
    
    Test(int x) : x(x) {
        cout << "Constructing Test(" << x << ")" << endl;
    }

    ~Test() {
        cout << "Destroying Test(" << x << ")" << endl;
    }

    void greet() const {
        cout << "Hello! x = " << x << endl;
    }
};

int main() {
    my_unique_ptr<Test> t(new Test(55));
    (*t).greet();	     // Hello! x = 55

    my_unique_ptr<Test> p = make_my_unique_ptr<Test>(42);
    p->greet();              // Hello! x = 42

    my_unique_ptr<Test> q = move(p);


    if (!p) cout << "p is now null" << endl;

    q->greet();              // Hello! x = 42

    return 0;
}

