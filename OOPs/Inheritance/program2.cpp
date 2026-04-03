#include <bits/stdc++.h>
using namespace std;

// class A
// {
// public:
//   A() { cout << "A\n"; }
// };

// class B : public A //!   Two copies of A exist (diamond problem)
// {
// public:
//   B() { cout << "B\n"; }
// };

// class C : public A
// {
// public:
//   C() { cout << "C\n"; }
// };

// class D : public B, public C // left to right B->C so B in turns call A then B and then C will call A and then C constructor
// {
// public:
//   D() { cout << "D\n"; }
// };

// int main()
// {
//   D obj;
// }

//! Only one A is created due to virtual

class A
{
public:
  A() { cout << "A\n"; }
};

class B : virtual public A
{
public:
  B() { cout << "B\n"; }
};

class C : virtual public A
{
public:
  C() { cout << "C\n"; }
};

class D : public B, public C
{
public:
  D() { cout << "D\n"; }
};

int main()
{
  D obj;
}