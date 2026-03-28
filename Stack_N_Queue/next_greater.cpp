#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {1,4,2,3,5,8,7};
  int n = arr.size();
  vector<int> res(n);

  stack<int> st;
  for(int i=n-1;i>=0;i--)
  {
    while(!st.empty() && (st.top() <= arr[i]))
    {
      st.pop();
    }

    if(st.empty())
    res[i] = -1;
    else
    res[i] = st.top();

    st.push(arr[i]);
  }

  for(auto it : res)
  cout<<it<<" ";
}