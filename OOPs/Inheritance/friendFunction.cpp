/*Like friend classes, a friend function can be granted special access to private and protected members of a class in C++. They are not the member functions of the class but can access and manipulate the private and protected members of that class for they are declared as friends.*/

//! Global function :

#include <iostream>
using namespace std;

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

  friend void friendFunction(base &obj);
};

void friendFunction(base &obj)
{
  cout << "Private Variable: " << obj.private_variable << endl;
  cout << "Protected Variable: " << obj.protected_variable;
}

int main()
{
  base object1;
  friendFunction(object1);
  return 0;
}

//!  Member Function of Another Class as Friend Function :

/*We can also declare a member function of another class as a friend function in C++. Forward declaration of the class is needed if we want to make a member function of another class a friend inside that class.
 */

#include <iostream>
using namespace std;

class base;

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
  cout << "Private Variable: " << obj.private_variable << endl;
  cout << "Protected Variable: " << obj.protected_variable;
}

int main()
{
  base object1;
  GFG object2;
  object2.GFG_Function(object1);

  return 0;
}