#include <bits/stdc++.h>
using namespace std;

long long dp[20][4][2];
vector<int> digits;

long long solve(int pos, int cnt, bool tight)
{
  if (cnt > 3)
    return 0;
  if (pos == digits.size())
    return 1;

  long long &res = dp[pos][cnt][tight];
  if (res != -1 && !tight)
    return res;

  long long ans = 0;
  int limit = tight ? digits[pos] : 9;

  for (int d = 0; d <= limit; d++)
  {
    ans += solve(
        pos + 1,
        cnt + (d != 0),
        tight && (d == limit));
  }

  if (!tight)
    res = ans;
  return ans;
}

long long countClassy(long long x)
{
  digits.clear();
  while (x > 0)
  {
    digits.push_back(x % 10);
    x /= 10;
  }
  reverse(digits.begin(), digits.end());

  memset(dp, -1, sizeof(dp));
  return solve(0, 0, true);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    long long l, r;
    cin >> l >> r;
    cout << countClassy(r) - countClassy(l - 1) << "\n";
  }
}
