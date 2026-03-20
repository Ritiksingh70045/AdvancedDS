#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix)
{
  stack<string> s;
  int n = postfix.size();

  for (int i = 0; i < n; i++)
  {
    char c = postfix[i];

    if (isalnum(c))
    {
      s.push(string(1, c));
    }
    else
    {
      string op2 = s.top();
      s.pop();
      string op1 = s.top();
      s.pop();
      s.push("(" + op1 + c + op2 + ")");
    }
  }

  return s.top();
}

int main()
{
  string postfix = "AB*C+";
  cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
  return 0;
}