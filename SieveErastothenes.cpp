#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= n; i++)
  {
    if (isPrime[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i])
    {
      cout << i << " ";
    }
  }
}

//*  Sieve of Eratosthenes to find prime factorization of multiple numbers efficiently

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<int> SPF(MAX_N + 1, 1);

class Solution
{
private:
  void sieve()
  {
    for (int i = 2; i * i <= MAX_N; i++)
    {

      if (SPF[i] == 1)
      {

        for (int j = i; j <= MAX_N; j += i)
        {

          if (SPF[j] == 1)
          {
            SPF[j] = i;
          }
        }
      }
    }

    return;
  }

  vector<int> primeFact(int n)
  {

    vector<int> ans;

    while (n != 1)
    {

      ans.push_back(SPF[n]);

      n = n / SPF[n];
    }

    return ans;
  }

public:
  vector<vector<int>> primeFactors(vector<int> &queries)
  {

    sieve();
    vector<vector<int>> ans;

    for (int i = 0; i < queries.size(); i++)
    {

      ans.push_back(primeFact(queries[i]));
    }
    return ans;
  }
};

int main()
{
  vector<int> queries = {2, 3, 4, 5, 6};

  Solution sol;

  vector<vector<int>> ans = sol.primeFactors(queries);

  cout << "The prime factorization of all the numbers is: " << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "For " << queries[i] << ": ";
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}