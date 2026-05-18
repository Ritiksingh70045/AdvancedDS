#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node(int _val, Node *nxt = nullptr)
  {
    val = _val;
    next = nxt;
  }
};
Node *reverse(Node *head)
{
  if (!head || !head->next)
    return nullptr;

  Node *temp = head;
  Node *prev = nullptr;

  while (temp)
  {
    Node *nxt = temp->next;
    temp->next = prev;
    prev = temp;

    temp = nxt;
  }
  temp = prev;
  return temp;
}
Node *sum(Node *a, Node *b)
{
  a = reverse(a);
  b = reverse(b);

  int carry = 0;
  Node* ans = new Node(-1);
  Node* headAns = ans;

  while(a && b)
  {
    int value = a->val + b->val + carry;
    carry = value/10;
    ans->next = new Node(value%10);
    ans = ans->next;
    a = a->next;
    b = b->next;
  }

  while(a)
  {
    int value = a->val + carry;
    carry = value/10;
    ans->next = new Node(value%10);
    ans = ans->next;
    a = a->next;
  }

  while(b)
  {
    int value = b->val + carry;
    carry = value/10;
    ans->next = new Node(value%10);
    ans = ans->next;
    b = b->next;
  }

  if(carry)
  {
    ans->next = new Node(carry);
  }

  ans = reverse(headAns->next);
  return ans;
}
int main()
{
  Node *a = new Node(9);
  a->next = new Node(9);
  a->next->next = new Node(9);
  a->next->next->next = new Node(0);
  Node *b = new Node(9);
  b->next = new Node(1);
  b->next->next = new Node(0);
  Node *result = sum(a, b);

  Node *temp = result;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
}