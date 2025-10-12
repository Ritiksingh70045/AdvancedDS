#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;

  Node(int data)
  {
    val = data;
    next = NULL;
    prev = NULL;
  }

  void PrintLL(Node* head)
  {
    Node* temp = head;
    while(temp != NULL)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
  }

  Node* createDLL(vector<int>& arr)
  {
    Node* head = new Node(arr[0]);
    head->prev = NULL;
    Node* temp = head;
    for(int i=1;i<arr.size();i++)
    {
      Node* newNode = new Node(arr[i]);
      temp->next = newNode;
      newNode->prev = temp;
      temp = temp->next;
    }
    temp->next = NULL;
    return head;
  }
};

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  Node* temp = new Node(0);
  temp->next = temp->createDLL(arr);
  (temp->next)->PrintLL(temp->next);
}