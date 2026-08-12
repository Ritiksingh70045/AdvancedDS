//! Default Constructor ...



#include <bits/stdc++.h>
using namespace std;

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    // No copy constructor → default shallow copy

    ~Demo() {
        cout << "Deleting memory\n";
        delete data;
    }
};

int main() {
    Demo obj1(10);
    Demo obj2 = obj1;   // shallow copy

    *obj2.data = 20;

    cout << "obj1: " << *obj1.data << endl;
    cout << "obj2: " << *obj2.data << endl;

    return 0;
}