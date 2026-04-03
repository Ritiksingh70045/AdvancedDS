#include <bits/stdc++.h>
using namespace std;

//* Problem 1.

// class A
// {
// public:
//   A(int x) { cout << "A " << x << endl; }
// };

// class B : public A
// {
// public:
//   B() : A(10)
//   {
//     cout << "B\n";
//   }
// };

// int main()
// {
//   B b;
// }

//*  Problem 2.

class A
{
public:
  A() { cout << "A\n"; }
};

class B : public A
{
public:
  B() { cout << "B\n"; }
};

class C : public B
{
public:
  C() : B() //!  👉 You cannot directly call grandparent (A) , 👉 Only immediate base (B) is allowed
  {              // ❌ trying to control order
    cout << "C\n";
  }
};

int main()
{
  C c;
}