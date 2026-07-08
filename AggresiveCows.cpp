#include <bits/stdc++.h>
using namespace std;

bool possible(int dist, vector<int> &arr, int n, int k)
{
  int cnt = 1;
  int last = 0;
  int i = 1;
  while (i < n)
  {
    if ((arr[i] - arr[last]) >= dist)
    {
      cnt++;
      last = i;
    }
    i++;
  }
  return (cnt >= k);
}
int main()
{
  int n, k; //  k <= n
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  int high = arr[n - 1] - arr[0];
  int low = 0;
  int res = -1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (possible(mid, arr, n, k))
    {
      res = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  cout << res;
}