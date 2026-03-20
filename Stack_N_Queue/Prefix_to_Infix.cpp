#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string prefix)
{
  stack<string> s;
  int n = prefix.size();

  for (int i = n - 1; i >= 0; i--)          // from back cause always two elements at back cause it is prefix
  {
    char c = prefix[i];

    if (isalnum(c))
    {
      s.push(string(1, c));
    }
    else
    {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      s.push("(" + op1 + c + op2 + ")");
    }
  }

  return s.top();
}

int main()
{
  string prefix = "*-A/BC-/AKL";
  cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
  return 0;
}