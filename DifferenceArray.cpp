#include <bits/stdc++.h>
using namespace std;

// Function to rebuild final array from difference array
vector<int> buildFinalArray(vector<int> &diff)
{
  int n = diff.size();
  vector<int> arr(n);
  arr[0] = diff[0];
  for (int i = 1; i < n; i++)
  {
    arr[i] = arr[i - 1] + diff[i];
  }
  return arr;
}

// Function to perform range update [l, r] += val
void rangeUpdate(vector<int> &diff, int l, int r, int val)
{
  diff[l] += val;
  if (r + 1 < diff.size())
    diff[r + 1] -= val;
}

int main()
{
  // ----------------------------
  // CASE 1: All Zero Array
  // ----------------------------
  cout << "=== Case 1: Array initially all zeros ===\n";
  int n = 5;
  vector<int> arr1(n, 0);
  vector<int> diff1(n, 0); // since arr1 all zeros

  // Range update: add +5 to [1, 3]
  rangeUpdate(diff1, 1, 3, 5);
  rangeUpdate(diff1, 1, 3, 5);


  // Build final array
  vector<int> final1 = buildFinalArray(diff1);

  cout << "Final array: ";
  for (int x : final1)
    cout << x << " ";
  cout << "\n\n";

  // ----------------------------
  // CASE 2: Non-zero Array
  // ----------------------------
  cout << "=== Case 2: Array with non-zero values ===\n";
  vector<int> arr2 = {2, 3, 5, 7, 11};
  vector<int> diff2(n);

  // Build difference array
  diff2[0] = arr2[0];
  for (int i = 1; i < n; i++)
    diff2[i] = arr2[i] - arr2[i - 1];

  // Range update: add +5 to [1, 3]
  rangeUpdate(diff2, 1, 3, 5);

  // Build final array
  vector<int> final2 = buildFinalArray(diff2);

  cout << "Final array: ";
  for (int x : final2)
    cout << x << " ";
  cout << "\n";

  return 0;
}
