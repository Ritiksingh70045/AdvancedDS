#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {-3, -5, -10, -10, -32};
  int n = nums.size();

  int sum = 0;
  int maxi = INT_MIN;           // For working in both -ve and +ve array elements.

  int start = 0, ansL = 0, ansR = 0;

  for (int i = 0; i < n; i++)
  {
    if (sum == 0)
      start = i;

    sum += nums[i];

    if (sum > maxi)
    {
      maxi = sum;
      ansL = start;
      ansR = i;
    }

    if (sum < 0)
      sum = 0;
  }

  cout << maxi << '\n';
  cout << ansL << " " << ansR << '\n';
}