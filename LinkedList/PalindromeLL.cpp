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

  Node *reverse(Node *node)
  {
    Node *prev = nullptr;

    while (node)
    {
      Node *nxt = node->next;

      node->next = prev;

      prev = node;
      node = nxt;
    }

    return prev;
  }

  void checkPalindrome()
  {
    if (!orgHead || !orgHead->next)
    {
      cout << "Palindrome\n";
      return;
    }

    Node *slow = orgHead;
    Node *fast = orgHead;
    Node *prev = nullptr;

    while (fast && fast->next)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // odd length
    if (fast)
    {
      slow = slow->next;
    }

    Node *result = reverse(slow);

    Node *temp = orgHead;

    while (temp && result)
    {
      if (temp->val != result->val)
      {
        cout << "Not Palindrome\n";
        return;
      }

      temp = temp->next;
      result = result->next;
    }

    cout << "Palindrome\n";
  }
};

int main()
{
  LL list;

  list.create(1);
  list.create(2);
  list.create(3);
  list.create(3);
  list.create(2);
  list.create(1);

  list.checkPalindrome();
}