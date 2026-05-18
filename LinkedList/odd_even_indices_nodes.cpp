#include <bits/stdc++.h>
using namespace std;

class LL
{
private:
  class Node
  {
  public:
    int val;
    Node *next;

    Node(int key)
    {
      val = key;
      next = nullptr;
    }
  };

  Node *head;
  Node *orgHead;

public:
  LL()
  {
    head = nullptr;
    orgHead = nullptr;
  }

  void create(int key)
  {
    Node *newNode = new Node(key);

    if (head == nullptr)
    {
      head = newNode;
      orgHead = newNode;
    }
    else
    {
      head->next = newNode;
      head = head->next;
    }
  }

  void solve()
  {
    if (!orgHead || !orgHead->next)
      return;

    Node *odd = orgHead;
    Node *even = orgHead->next;

    Node *evenHead = even;

    while (even && even->next)
    {
      odd->next = even->next;
      odd = odd->next;

      even->next = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
  }
};

int main()
{
  LL list;

  list.create(1);
  list.create(2);
  list.create(3);
  list.create(4);
  list.create(5);
  list.create(6);
}