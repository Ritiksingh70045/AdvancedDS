#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> forward(n, 1);
  vector<int> backward(n, 1);

  for (int i = 0; i < n; i++)
  {
    for (int prev = 0; prev < i; prev++)
    {
      if ((arr[prev] < arr[i]) && (1 + forward[prev] > forward[i]))
      {
        forward[i] = 1 + forward[prev];
      }
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int next = n - 1; next > i; next--)
    {
      if (arr[next] < arr[i] && (backward[next] + 1 > backward[i]))
      {
        backward[i] = 1 + backward[next];
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    ans = max(ans, forward[i] + backward[i] - 1);
  }

  cout<<ans;
}