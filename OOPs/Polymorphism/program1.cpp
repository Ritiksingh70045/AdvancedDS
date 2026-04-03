#include <bits/stdc++.h>
using namespace std;

// class A{
//   public:
//   virtual void show()
//   {
//     cout<<"A"<<'\n';
//   }
// };

// class B : public A{
//   public:
//   void show() override
//   {
//     cout<<"B"<<'\n';
//   }
// };

class A
{
public:
  virtual void show(int x)
  {
    cout << "A\n";
  }
};

class B : public A
{
public:
  void show()
  { // ❌ different signature
    cout << "B\n";
  }
};

int main()
{
  B b;
  b.show();
}


//!   “Without virtual, function calls are resolved at compile time using pointer type, not object type.”
//!    “Signature mismatch prevents overriding, leading to base class function call.”
/*
      A* ptr = new B();
      ptr->show();   // decided at compile time → A::show()
*/