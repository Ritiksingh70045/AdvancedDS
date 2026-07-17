#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long double minimiseMaxDistance(vector<int> &arr, int k)
  {
    int n = arr.size();
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
      long double length = arr[i + 1] - arr[i];
      pq.push({length, i});
    }
    vector<int> howMany(n , 0);
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
      auto top = pq.top();
      pq.pop();
      int segmentIndex = top.second;

      howMany[segmentIndex]++;
      long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
      long double newLen = totalDist / (howMany[segmentIndex] + 1);
      pq.push({newLen, segmentIndex});
    }

    return pq.top().first;
  }
};

int main()
{
  vector<int> arr = {1, 2, 3, 4, 7};
  int k = 2;
  Solution obj;
  long double ans = obj.minimiseMaxDistance(arr, k);
  cout << "The answer is: " << ans << "\n";
  return 0;
}