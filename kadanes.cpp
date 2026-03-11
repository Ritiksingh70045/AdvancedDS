#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int currsum = arr[0];
  int maxsum = arr[0];

  for(int i=1;i<n;i++)
  {
    currsum = max(arr[i] , arr[i]+currsum);
    maxsum = max(maxsum , currsum);
  }
  cout<<maxsum;
}