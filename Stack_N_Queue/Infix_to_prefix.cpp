#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
            result += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && (prec(c) < prec(st.top()))) // In infix to prefix, we reverse the expression, which reverses associativity. So we use < instead of <= to maintain correct operator order.
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix expression: " << exp << endl;
    cout << "Prefix expression: " << infixToPrefix(exp) << endl;
    return 0;
}