#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *links[26];
  bool flag;

  Node()
  {
    flag = false;
    for (int i = 0; i < 26; i++)
    {
      links[i] = nullptr;
    }
  }

  bool containsKey(char ch)
  {
    return links[ch - 'a'] != nullptr;
  }

  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }

  void setEnd()
  {
    flag = true;
  }

  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(string word)
  {
    Node *node = root;

    for (char ch : word)
    {
      if (!node->containsKey(ch))
      {
        node->put(ch, new Node());
      }
      node = node->get(ch);
    }

    node->setEnd();
  }

  bool check(string word)
  {
    Node *node = root;

    for (char ch : word)
    {
      if (!node->containsKey(ch))
        return false;

      node = node->get(ch);

      if (!node->isEnd())
        return false;
    }

    return true;
  }
};

string completeString(int n, vector<string> &a)
{
  Trie trie;

  for (auto &word : a)
    trie.insert(word);

  string longest = "";

  for (auto &word : a)
  {
    if (trie.check(word))
    {
      if (word.length() > longest.length())
      {
        longest = word;
      }
      else if (word.length() == longest.length() && word < longest)
      {
        longest = word;
      }
    }
  }

  return longest.empty() ? "None" : longest;
}

int main()
{
  int n = 6;
  vector<string> a = {"n", "ni", "nin", "ninj", "ninja", "ninga"};

  cout << completeString(n, a) << endl;

  return 0;
}