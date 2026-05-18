#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *prev;
  Node *next;

  Node(int _val, Node *_prev = nullptr, Node *_next = nullptr)
  {
    val = _val;
    prev = _prev;
    next = _next;
  }
};

void delete_node(Node *head, int k)
{
  Node *temp = head;
  while (temp)
  {
    if (temp->val == k)
    {
      Node* todel = temp;
      if (temp->prev == nullptr)
      {
        temp->next->prev = nullptr;
        
      }
    }
  }
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2, head);
  head->next->next = new Node(1, head->next);
  head->next->next->next = new Node(3, head->next->next);

  delete_node(head, k)
}