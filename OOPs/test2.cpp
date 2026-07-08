#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
  virtual void display()
  {
    cout << "Base class function";
  }
};

class Derived : public Base
{
public:
  void display() override
  {
    cout << "Derived class function";
  }
};

int main()
{

  Base *basePtr  = new Derived();

  Derived derivedObj;

  basePtr = &derivedObj;

  basePtr->display();
  return 0;
}