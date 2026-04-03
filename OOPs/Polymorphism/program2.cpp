#include <bits/stdc++.h>
using namespace std;

class A
{
public:
  virtual void show(int x = 10)
  {
    cout << "A " << x << endl;
  }
};

class B : public A
{
public:
  void show(int x = 20) override
  {
    cout << "B " << x << endl;
  }
};

int main()
{
  A *ptr = new B();
  ptr->show();
}

/*

  👉 Two things happen here:

            1. Function call (runtime)
            A* ptr = new B();
            ptr->show();
            show() is virtual
            So function resolved at runtime
            👉 Calls: B::show()
            2. Default argument (compile-time)
            Pointer type is A*
            👉 So default value comes from A
            x = 10
Final Execution
B::show(10)

👉 Output:

B 10

*/

//!   “Virtual functions are resolved at runtime, but default arguments are resolved at compile time.”