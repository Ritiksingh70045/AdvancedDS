#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pattern)
{
  int m = pattern.size();
  vector<int> lps(m, 0);
  int len = 0; // length of previous longest prefix-suffix

  for (int i = 1; i < m;)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1]; // fallback
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

vector<int> KMP(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  vector<int> lps = buildLPS(pattern);
  vector<int> positions;

  int i = 0, j = 0; // i for text, j for pattern
  while (i < n)
  {
    if (text[i] == pattern[j])
    {
      i++, j++;
    }

    if (j == m)
    {
      positions.push_back(i - j); // match found at i - j
      j = lps[j - 1];             // continue checking
    }
    else if (i < n && text[i] != pattern[j])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return positions;
}

int main()
{
  string text = "aaabaaabaaaabaaabaaaab";
  string pattern = "aaabaaa";

  vector<int> result = KMP(text, pattern);

  cout << "Pattern found at indices: ";
  for (int index : result)
  {
    cout << index << " ";
  }
  cout << endl;

  return 0;
}