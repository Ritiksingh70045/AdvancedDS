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

    Node(int key, Node *nxt = nullptr)
    {
      val = key;
      next = nxt;
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
  void createLL(int key)
  {
    Node *newnode = new Node(key);
    if (!head)
    {
      head = newnode;
      orgHead = newnode;
    }
    else
    {
      head->next = newnode;
      head = head->next;
    }
  }
  void middle()
  {
    Node *slow = orgHead;
    Node *fast = orgHead;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    cout << slow->val;
  }
};

int main()
{
  LL list;
  list.createLL(1);
  list.createLL(2);
  list.createLL(3);
  list.createLL(4);
  list.createLL(5);
  list.createLL(6);
  list.createLL(7);
  // list.createLL(8);
  // list.createLL(9);

  list.middle();
}