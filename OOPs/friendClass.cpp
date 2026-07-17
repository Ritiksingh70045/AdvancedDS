#include <iostream>
using namespace std;

class Geeks
{
private:
  int private_variable;

protected:
  int protected_variable;

public:
  Geeks()
  {
    private_variable = 10;
    protected_variable = 99;
  }

  friend class GFG;
};

class GFG
{
public:
  void display(Geeks &t)
  {
    cout << "The value of Private Variable = "
         << t.private_variable << endl;
    cout << "The value of Protected Variable = "
         << t.protected_variable;
  }
};

int main()
{
  Geeks g;
  GFG fri;
  fri.display(g);
  return 0;
}