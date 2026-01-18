#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void quickSort(vector<int> &arr, int low, int high)
  {
    if (low < high)
    {
      int pivotIndex = partition(arr, low, high);

      quickSort(arr, low, pivotIndex - 1);

      quickSort(arr, pivotIndex + 1, high);
    }
  }

  int partition(vector<int> &arr, int low, int high)
  {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
      if (arr[j] <= pivot)
      {
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
  }
};

int main()
{
  vector<int> arr = {10, 7, 8, 9, 1, 5};

  Solution sol;

  sol.quickSort(arr, 0, arr.size() - 1);

  for (int num : arr)
    cout << num << " ";

  return 0;
}
