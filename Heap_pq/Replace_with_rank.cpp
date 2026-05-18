#include<bits/stdc++.h>
using namespace std;
struct comp{
  bool operator()(pair<int,int>& p1, pair<int,int>& p2)
  {
    if(p1.first == p2.first)
    return p1.second > p2.second;
    return p1.first > p2.first;
  }
};
int main()
{
  vector<int> nums = {56,7,3,9,43,9,65,65};
  int n = nums.size();
  priority_queue<pair<int,int> , vector<pair<int,int>> , comp> pq;
  for(int i=0;i<n;i++)
  {
    pq.push({nums[i] , i});
  }
  int count = 0;
  while(!pq.empty())
  {
    count++;
    int val = pq.top().first;
    int ind = pq.top().second;
    pq.pop();
    nums[ind] = count;
  }
  for(auto it : nums)
  cout<<it<<" ";
}