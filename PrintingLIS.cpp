#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> dp(n, 1);
  vector<int> hash(n, 1);

  for (int i = 0; i < n; i++)
  {
    hash[i] = i;
    for (int prevInd = 0; prevInd < i; prevInd++)
    {
      if (arr[prevInd] < arr[i] && (1 + dp[prevInd]) > dp[i])
      {
        dp[i] = 1 + dp[prevInd];
        hash[i] = prevInd;
      }
    }
  }

  int ans = -1;
  int lastIndex = -1;

  for (int i = 0; i < n; i++)
  {
    if (dp[i] > ans)
    {
      ans = dp[i];
      lastIndex = i;
    }
  }

  vector<int> temp;
  temp.push_back(arr[lastIndex]);

  while (hash[lastIndex] != lastIndex)
  {
    lastIndex = hash[lastIndex];
    temp.push_back(arr[lastIndex]);
  }

  reverse(temp.begin(), temp.end());

  for (auto it : temp)
    cout << it << " ";
}