/*A friend class can access private and protected members of other classes in which it is declared as a friend.

Remember one thing, friendship is not mutual. If class A is a friend of B, then B doesn't become a friend of A automatically.
We can declare a friend class in C++ by using the friend keyword.*/

#include <bits/stdc++.h>
using namespace std;

class A
{
private:
  int priv;

protected:
  int pro;

public:
  A()
  {
    priv = 10;
    pro = 20;
  }
  friend class B;
};

class B
{
public:
  void display(A &a)
  {
    cout << a.priv << " " << a.pro << '\n';
  }
};

int main()
{
  A a;
  B b;
  b.display(a);
}