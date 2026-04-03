class Solution
{
public:
  struct compare
  {
    bool operator()(ListNode *a, ListNode *b)
    {
      return a->val > b->val; // min heap
    }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    // Step 1: push all heads
    for (auto list : lists)
    {
      if (list)
        pq.push(list);
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy;

    while (!pq.empty())
    {
      ListNode *node = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;

      if (node->next)
      {
        pq.push(node->next);
      }
    }

    return dummy->next;
  }
};