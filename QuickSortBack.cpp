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
        i++;               // 'i' will after incrementing simply go to the number greater than the pivot and replace with the small number('j' is pointing to this number) found as compared to the pivot.
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[high]);  // this is required for high to place to the correct position and then return the i+1 because i is pointing to the number smaller than the pivot and i+1 is pointing to the number greater than the pivot that's why we will be storing pivot at i+1 so that it's go to it's correct position.

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
