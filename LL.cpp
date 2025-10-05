#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

public:
  ListNode(int value)
  {
    val = value;
    next = nullptr;
  }

  ListNode(int value, ListNode *next)
  {
    val = value;
    next = next;
  }

  void printLL(ListNode *node)
  {
    ListNode *temp = node;
    while (temp)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout<<"\n";
  }

  ListNode *reverseLL(ListNode *node)
  {
    ListNode *temp1 = nullptr;
    ListNode *temp2 = node;
    ListNode *temp3 = node->next;

    while (temp2->next != nullptr)
    {
      temp2->next = temp1;
      temp1 = temp2;
      temp2 = temp3;
      temp3 = temp3->next;
    }
    temp2->next = temp1;
    return temp2;
  }

  void detectCycle(ListNode *node)
  {
    ListNode *slow = node;
    ListNode *fast = node;
    while (fast && fast->next)
    {
      if (fast == slow)
      {
        cout << "Cycle Exists" << '\n';
        return;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    cout << "Cycle not exists" << '\n';
  }

  bool palidrome(ListNode* node)
  {
    
  }
};

int main()
{
  ListNode *node = new ListNode(1);
  node->next = new ListNode(2);
  node->next->next = new ListNode(3);
  node->next->next->next = new ListNode(4);
  node->next->next->next->next = new ListNode(5);
  //* node->next->next->next->next->next = node;

  node->printLL(node);
  ListNode *rNode = node->reverseLL(node);
  node->printLL(rNode);
  node->detectCycle(node);
}