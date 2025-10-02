#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    int n;                 // Size of array
    vector<long long> bit; // Internal BIT array

public:
    // Constructor
    BIT(int size) {
        n = size;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    // Update: add 'val' to index 'idx'
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Query: prefix sum from 1 to idx
    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Range sum query: [l, r]
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    // Build from initial array
    void build(vector<int> &arr) {
        for (int i = 0; i < (int)arr.size(); i++) {
            update(i + 1, arr[i]); // shifting to 1-based index
        }
    }
};

// Example usage
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    BIT fenwick(n);
    fenwick.build(arr);

    cout << "Prefix sum till index 3: " << fenwick.query(3) << "\n";
    cout << "Range sum [2,5]: " << fenwick.rangeQuery(2, 5) << "\n";

    fenwick.update(4, 10); // Add 10 at index 4
    cout << "After update, range sum [2,5]: " << fenwick.rangeQuery(2, 5) << "\n";

    return 0;
}
