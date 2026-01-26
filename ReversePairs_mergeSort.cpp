#include <bits/stdc++.h>
using namespace std;

long long countInv;

void merge(int low, int mid, int high, vector<int> &arr)
{
  vector<int> temp;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]);
  }

  while (left <= mid)
    temp.push_back(arr[left++]);

  while (right <= high)
    temp.push_back(arr[right++]);

  for (int i = low; i <= high; i++)
    arr[i] = temp[i - low];
}

void mergeSort(int low, int high, vector<int> &arr)
{
  if (low >= high)
    return;

  int mid = low + (high - low) / 2;

  mergeSort(low, mid, arr);
  mergeSort(mid + 1, high, arr);

  int j = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (j <= high && (long long)arr[i] > 2LL * arr[j])
    {
      j++;
    }
    countInv += (j - (mid + 1));
  }

  merge(low, mid, high, arr);
}

int main()
{
  countInv = 0;
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  mergeSort(0, n - 1, arr);

  cout << "Reverse pairs = " << countInv << endl;
}
