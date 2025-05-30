#include <iostream>

#include "Resource.h"

using namespace std;

int main() {
    shared_ptr<Resource> ptr1 = make_shared<Resource>("MyResource");

    cout << "Use count after ptr1 creation: " << ptr1.use_count() << endl;

    {
        shared_ptr<Resource> ptr2 = ptr1;
        cout << "Use count after ptr2 creation: " << ptr1.use_count() << endl;

        {
            shared_ptr<Resource> ptr3 = ptr2;
            cout << "Use count after ptr3 creation: " << ptr1.use_count() << endl;

            ptr3->print();
        }

        cout << "Use count after ptr3 is out of scope: " << ptr1.use_count() << endl;
    }

    cout << "Use count after ptr2 is out of scope: " << ptr1.use_count() << endl;

    ptr1->print();

    return 0;
}

