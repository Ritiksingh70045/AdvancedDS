#include <bits/stdc++.h>
using namespace std;

//! Using single Queue
// int main()
// {
//   queue<int> q;
//   vector<int> arr = {1,2,3,4,5};

//   int i=0;
//   while(i<5)
//   {
//     int size = q.size();
//     q.push(arr[i]);
//     for(int j=0;j<size;j++)
//     {
//       q.push(q.front());
//       q.pop();
//     }
//     i++;
//   }

//   int k = 5;
//   while(k--)
//   {
//     cout<<q.front()<<" ";
//     q.pop();
//   }
// }

//! Using two queue

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  queue<int> q1, q2;
  int i = 0;
  while (i < 5)
  {
    int size = q1.size();
    while (size--)
    {
      q2.push(q1.front());
      q1.pop();
    }
    q1.push(arr[i]);
    size = q2.size();
    while (size--)
    {
      q1.push(q2.front());
      q2.pop();
    }
    i++;
  }
  int k = 5;
  while (k--)
  {
    cout << q1.front() << " ";
    q1.pop();
  }
}