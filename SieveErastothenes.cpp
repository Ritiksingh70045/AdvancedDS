#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findAllPrimes(int n)
  {

    vector<int> prime(n + 1, 1);

    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= n; ++i)
    {
      if (prime[i])
      {
        for (int j = i * i; j <= n; j += i)
        {
          prime[j] = 0;
        }
      }
    }

    vector<int> ans;
    for (int i = 2; i <= n; ++i)
    {
      if (prime[i])
        ans.push_back(i);
    }

    return ans;
  }
};

// Driver code
int main()
{
  int n = 32;

  Solution obj;
  vector<int> primes = obj.findAllPrimes(n);

  cout << "Prime numbers <= " << n << ":" << endl;
  for (int prime : primes)
  {
    cout << prime << " ";
  }
  cout << endl;

  return 0;
}
