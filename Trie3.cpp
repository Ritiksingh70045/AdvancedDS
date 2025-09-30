#include<bits/stdc++.h>
using namespace std;
struct Node{
  Node* links[26],
  bool flag = false;

  bool containsKey(char ch)
  {
    return links[ch-'a'] != NULL;
  }
  Node* get(char ch)
  {
    return links[ch-'a'];
  }

}
int main()
{
  
}