#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string postfix)
{
  stack<string> s;
  int n = postfix.size();

  for (int i = 0; i < n; i++)
  {
    char c = postfix[i];

    if (isalnum(c))
    {
      s.push(string(1, c));         // way to convert a character to string
    }
    else
    {
      string op2 = s.top();
      s.pop();
      string op1 = s.top();
      s.pop();
      s.push(c + op1 + op2);
    }
  }

  return s.top();
}

int main()
{
  string postfix = "abc*+d-";
  cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
  return 0;
}