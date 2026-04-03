#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  int n = nums.size();
  vector<int> ans;
  deque<int> dq;

  for (int i = 0; i < n; i++)
  {
    if (!dq.empty() && dq.front() <= i - k)
      dq.pop_front();

    while (!dq.empty() && nums[dq.front()] < nums[i])
    {
      dq.pop_back();
    }

    dq.push_back(i);
    if (i >= k - 1)
      ans.push_back(nums[dq.front()]);
  }

  for (auto it : ans)
    cout << it << " ";
}