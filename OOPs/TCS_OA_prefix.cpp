#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePrefix(string prefix)
{
  stack<int> st;

  for (int i = prefix.length() - 1; i >= 0; i--)
  {
    char ch = prefix[i];

    if (ch == ' ')
      continue;

    if (isdigit(ch))
    {
      st.push(ch - '0');
    }
    else
    {
      int operand1 = st.top();
      st.pop();

      int operand2 = st.top();
      st.pop();

      switch (ch)
      {
      case '+':
        st.push(operand1 + operand2);
        break;
      case '-':
        st.push(operand1 - operand2);
        break;
      case '*':
        st.push(operand1 * operand2);
        break;
      case '/':
        st.push(operand1 / operand2);
        break;
      case '%':
        st.push(operand1 % operand2);
        break;
      }
    }
  }

  return st.top();
}

int main()
{
  string prefix = "*+234";
  cout <<"Dekh le answer : " << evaluatePrefix(prefix);
}