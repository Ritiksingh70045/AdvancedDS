#include <bits/stdc++.h>
using namespace std;

struct DLL
{
private:
  class Node
  {
    int val;
    Node *next;
    Node *prev;

  public:
    Node(int val, Node *next, Node *prev)
    {
      this->val = val;
      this->next = next;
      this->prev = prev;
    }
  };
  Node* head;
public : 
  LL()
  {
    head = nullptr;
  }
  
};