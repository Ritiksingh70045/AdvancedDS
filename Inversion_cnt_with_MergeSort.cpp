#include<bits/stdc++.h>
using namespace std;

long long countInv;

void merge(int low, int mid, int high, vector<int>& arr)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            countInv += (mid - left + 1);   // 🔧 CHANGED: correct inversion count  from this left to mid all will be greater than the right one.
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int low, int high, vector<int>& arr)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

int main()
{
    countInv = 0;   // 🔧 CHANGED: initialize long long counter

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1, arr);

    // sorted array
    for (int x : arr)
        cout << x << " ";

    cout << "\nInversion count = " << countInv << endl;
}
