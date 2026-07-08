#include <bits/stdc++.h>
using namespace std;

class A
{
public:
  A()
  {
    cout << "Constructor A\n";
  }
};

class B : public A
{
public:
  B()
  {
    cout << "Constructor B\n";
  }
};

class C : public B
{
public:
  C()
  {
    cout << "Constructor C\n";
  }
};

int main()
{
  C obj;
}