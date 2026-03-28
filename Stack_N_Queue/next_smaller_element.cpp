#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {4, 6, 5, 2, 7, 3};
  int n = arr.size();

  stack<int> st;
  vector<int> res(n);

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && (st.top() >= arr[i]))
      st.pop();

    if (st.empty())
      res[i] = -1;
    else
      res[i] = st.top();

    st.push(arr[i]);
  }

  for (auto it : res)
    cout << it << " ";
}