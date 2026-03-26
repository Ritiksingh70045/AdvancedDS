//*  Why functions cannot be overloaded based on return type?   (Some exception case)

// C++ doesn't allow function overloading by changing the return type. It is because the return type is not included in the function call, due to which the compiler won't be able to distinguish between them resulting in ambiguity issue. Therefore, we cannot achieve function overloading by changing the return type only.

#include <iostream>
using namespace std;

string get()
{
  return "This returns string";
}
int get()
{
  return 99;
}

int main()
{
  string s = get();
  cout << s;

  return 0;
}