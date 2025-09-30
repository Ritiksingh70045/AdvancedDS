#include <bits/stdc++.h>
using namespace std;

long long minimumReplacement(vector<int> &nums)
{
  long long ops = 0;
  long long maxi = nums.back(); // last element is allowed max

  for (int i = nums.size() - 2; i >= 0; i--)
  {
    if (nums[i] <= maxi)
    {
      maxi = nums[i]; // already okay
    }
    else
    {
      // parts = ceil(nums[i] / (double)maxi)
      long long parts = (long long)ceil((double)nums[i] / maxi);

      ops += parts - 1; // number of splits = parts - 1

      maxi = (long long)floor((double)nums[i] / parts);
    }
  }

  return ops;
}

int main()
{
  vector<int> arr = {3, 4, 3};
  cout << minimumReplacement(arr) << endl; // Output: 2
  return 0;
}
