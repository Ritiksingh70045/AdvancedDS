#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node(int x)
  {
    val = x;
    next = NULL;
  }
};

class Solution
{
private:
  Node *head;
  int size;

public:
  Solution()
  {
    head = NULL;
    size = 0;
  }

  void push(int x)
  {
    Node *element = new Node(x);
    element->next = head;
    head = element;
    size++;
  }

  int pop()
  {
    if (head == NULL)
      return -1;
    Node *remNode = head;
    head = head->next;
    size--;
    int value = remNode->val;
    delete remNode;
    return value;
  }

  int top()
  {
    if (head == NULL)
      return -1;
    return head->val;
  }

  bool isEmpty()
  {
    return (size == 0);
  }
};

int main()
{
  Solution sol;
  sol.push(1);
  sol.push(2);
  sol.push(3);
  cout << sol.top() << '\n';
  cout << sol.pop() << '\n';
  cout << sol.top() << '\n';
}