#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {5,2,1};
  int n = nums.size();
  int total = (1<<n);
  vector<int> ans;
  for(int i=0;i<total;i++)
  {
    int sum = 0;
    for(int bit = 0;bit<n;bit++)
    {
      if(i & (1 << bit))
      {
        sum += nums[bit];
      }
    }
    ans.push_back(sum);
  }

  sort(ans.begin() , ans.end());
  for(auto it : ans)
  cout<<it<<" ";
}