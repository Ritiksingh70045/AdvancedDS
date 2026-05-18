#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int val, Node *nxt = nullptr)
  {
    data = val;
    next = nxt;
  }
};

class LL
{
public:
  Node *merge(Node *list1, Node *list2)
  {
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
      if (list1->data <= list2->data)
      {
        temp->next = list1;
        list1 = list1->next;
      }
      else
      {
        temp->next = list2;
        list2 = list2->next;
      }
      temp = temp->next;
    }
    if (list1 != nullptr)
      temp->next = list1;
    else
      temp->next = list2;

    return dummyNode->next;
  }

  Node *findmiddle(Node *head)
  {
    if (!head || !head->next)
      return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  Node *sortLL(Node *head)
  {
    if (!head || !head->next)
      return head;

    Node *middle = findmiddle(head);
    Node *right = middle->next;
    middle->next = nullptr;

    Node *left = head;

    left = sortLL(left);
    right = sortLL(right);

    return merge(left, right);
  }
};

void printLL(Node *head)
{
  Node *temp = head;

  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *head = new Node(3);
  head->next = new Node(2);
  head->next->next = new Node(5);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(1);

  cout << "Original Linked List: ";
  printLL(head);

  LL list;
  head = list.sortLL(head);

  cout << "Sorted Linked List" << " ";
  printLL(head);
}