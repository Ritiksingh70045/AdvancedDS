#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  int j = 0;
  int slen = s.length();

  int ans = 0;
  int cnt = n;
  vector<int> available(n, 1);
  while (cnt != 1)     // O(n) in worst case
  {
    if (i >= n)
      i %= n;
    if (j >= slen)
      j %= slen;

    while (available[i] == 0)   // O(n) in worst case
      i = (i + 1) % n;
    if (s[j] == 'a')
    {
      i++;
      j++;
    }
    else
    {
      available[i] = 0;
      cnt--;
      i++;
      j++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (available[i] == 1)
    {
      ans = i + 1;
      break;
    }
  }
  cout << ans;
}

// TC : O(n^2)