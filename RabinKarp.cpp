#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp algorithm for substring search
vector<int> rabinKarp(string text, string pattern)
{
  vector<int> result;
  int n = text.size();
  int m = pattern.size();
  if (m > n)
    return result;

  const int d = 256; // number of characters in the input alphabet
  const int q = 101; // a prime number

  long long p = 0; // hash value for pattern
  long long t = 0; // hash value for text
  long long h = 1;

  // The value of h would be "pow(d, m-1)%q"
  for (int i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate the hash value of pattern and first window of text
  for (int i = 0; i < m; i++)
  {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Slide the pattern over text one by one
  for (int i = 0; i <= n - m; i++)
  {
    // Check the hash values of current window of text and pattern.
    if (p == t)
    {
      // Check for characters one by one
      if (text.substr(i, m) == pattern)
        result.push_back(i);
    }

    // Calculate hash value for next window of text: Remove leading digit,
    // add trailing digit
    if (i < n - m)
    {
      t = (d * (t - text[i] * h) + text[i + m]) % q;
      if (t < 0)
        t += q; // Ensure t is non-negative
    }
  }

  return result;
}

int main()
{
  string text = "abcdef";
  string pattern = "de";

  vector<int> result = rabinKarp(text, pattern);

  cout << "Pattern found at indices: ";
  for (int index : result)
  {
    cout << index << " ";
  }
  cout << endl;

  return 0;
}