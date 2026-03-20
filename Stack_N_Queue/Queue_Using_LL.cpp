#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  Node *next;
  Node(int d)
  {
    val = d;
    next = NULL;
  }
};

class Queue
{
private:
  Node *start;
  Node *end;
  int size;

public:
  Queue()
  {
    start = end = NULL;
    size = 0;
  }

  void push(int x)
  {
    Node *element = new Node(x);

    if (start == NULL)
    {
      start = end = element;
    }
    else
    {
      end->next = element;
      end = element;
    }

    size++;
  }

  int pop()
  {
    if (start == NULL)
    {
      return -1;
    }

    int value = start->val;
    Node *temp = start;
    start = start->next;
    delete temp;
    size--;

    return value;
  }

  int peek()
  {
    if (start == NULL)
    {
      return -1;
    }

    return start->val;
  }

  bool isEmpty()
  {
    return (size == 0);
  }
};

int main()
{
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  cout << q.pop() << '\n';
  cout << q.pop() << '\n';
  cout << q.peek() << '\n';
  cout << q.isEmpty() << '\n';
}