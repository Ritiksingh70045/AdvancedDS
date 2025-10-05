#include <bits/stdc++.h>
using namespace std;

int partition(int low, int high, vector<int> &arr)
{
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j)
  {
    while (arr[i] <= pivot && i < high)
    {
      i++;
    }

    while (arr[j] > pivot && j > low)
    {
      j--;
    }

    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void qs(int low, int high, vector<int> &arr)
{
  if (low < high)
  {
    int pIndex = partition(low, high, arr);
    qs(low, pIndex, arr);
    qs(pIndex + 1, high, arr);
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  qs(0, n - 1, arr);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}