//! user defined constructor does deep copy ....


#include <bits/stdc++.h>
using namespace std;

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    // Deep Copy Constructor
    Demo(const Demo &obj) {
        data = new int(*(obj.data));
    }

    ~Demo() {
        cout << "Deleting memory\n";
        delete data;
    }
};

int main() {
    Demo obj1(10);
    Demo obj2 = obj1;   // deep copy

    *obj2.data = 20;

    cout << "obj1: " << *obj1.data << endl;
    cout << "obj2: " << *obj2.data << endl;

    return 0;
}