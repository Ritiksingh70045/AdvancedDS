#include <bits/stdc++.h>
using namespace std;

class A
{
public:
  A() { cout << "A_ctor "; }

  virtual void show(int x = 5)
  {
    cout << "A_show " << x << " ";
  }

  virtual ~A()
  {
    cout << "A_dtor ";
  }
};

class B : public A
{
public:
  B() { cout << "B_ctor "; }

  void show(int x = 10) override
  {
    cout << "B_show " << x << " ";
  }

  ~B()
  {
    cout << "B_dtor ";
  }
};

int main()
{
  A *ptr = new B();
  ptr->show();
  delete ptr;
}

/*  Constructor order (base → derived):

🔹 Function selection → runtime
virtual → calls B::show
🔹 Default argument → compile time
Pointer type = A* → uses x = 5

 Destructor order (derived → base)
*/