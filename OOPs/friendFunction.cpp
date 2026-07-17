#include <iostream>
using namespace std;

// Forward Declaration needed
class base;

// Another class in which function is declared
//! Need for it's declaration because base class is going to use that.
class GFG
{
public:
  void GFG_Function(base &obj);
};

class base
{
private:
  int private_variable;

protected:
  int protected_variable;

public:
  base()
  {
    private_variable = 10;
    protected_variable = 99;
  }

  friend void GFG::GFG_Function(base &);
};

void GFG::GFG_Function(base &obj)
{
  cout << "Private Variable: " << obj.private_variable
       << endl;
  cout << "Protected Variable: " << obj.protected_variable;
}

int main()
{
  base object1;
  GFG object2;
  object2.GFG_Function(object1);

  return 0;
}