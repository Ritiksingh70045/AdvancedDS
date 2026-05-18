#include <bits/stdc++.h>
using namespace std;

class LinkedList
{

  class Node
  {
  public:
    int val;
    Node *next;

    Node(int value, Node *nxt = nullptr)
    {
      val = value;
      next = nxt;
    }
  };

  Node *head;

public:
  LinkedList()
  {
    head = nullptr;
  }

  // insert at beginning
  void insertAtHead(int value)
  {
    Node *newNode = new Node(value, head);
    head = newNode;
  }

  // display list
  void print()
  {
    Node *temp = head;

    while (temp != nullptr)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
  }
};

int main()
{

  LinkedList list;

  list.insertAtHead(10);
  list.insertAtHead(20);
  list.insertAtHead(30);

  list.print();
}