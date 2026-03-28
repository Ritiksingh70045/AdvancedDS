#include <bits/stdc++.h>
using namespace std;

string solve(string str, int k)
{
  int n = str.length();
  stack<char> st;
  for (int i = 0; i < n; i++)
  {
    char digit = str[i];

    while (!st.empty() && k > 0 && st.top() > digit)
    {
      st.pop();
      k--;
    }

    st.push(digit);
  }
  while (!st.empty() && k)
  {
    st.pop();
    k--;
  }
  if (st.empty())
    return "0";

  string res = "";
  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }
  while (res.size() > 0 &&
         res.back() == '0')
  {

    res.pop_back();
  }

  reverse(res.begin(), res.end());

  if (res.empty())
    return "0";

  return res;
}

int main()
{
  string str = "5432991";
  int n = str.length();
  int k = 4;
  cout << solve(str, k);
}