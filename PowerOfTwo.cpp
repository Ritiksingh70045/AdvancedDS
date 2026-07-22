#include<bits/stdc++.h>
using namespace std;

int main()
{
  int num;
  cin>>num;

  int cnt = 0;
  for(int i=0;i<=31;i++)
  {
    if(num & (1<<i))
    cnt++;
  }
  if(cnt == 1)
  cout<<"YES"<<'\n';
  else
  cout<<"NO"<<'\n';
}