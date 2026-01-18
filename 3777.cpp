class Solution
{
public:
  struct Node
  {
    char left, right;
    int length;

    Node(char ch)
    {
      left = right = ch;
      length = 1;
    }

    Node(char l, char r, int len)
    {
      left = l;
      right = r;
      length = len;
    }
  };

  vector<Node *> seg;
  vector<char> arr;

  vector<int> minDeletions(string s, vector<vector<int>> &queries)
  {
    int n = s.size();
    arr.assign(s.begin(), s.end());

    int cnt = 0;
    for (auto &q : queries)
      if (q[0] == 2)
        cnt++;

    vector<int> ans(cnt);
    cnt = 0;

    seg.resize(4 * n, nullptr);
    build(0, 0, n - 1);

    for (auto &q : queries)
    {
      if (q[0] == 1)
      {
        updateTree(0, 0, n - 1, q[1]);
      }
      else
      {
        Node *currAns = queryTree(0, 0, n - 1, q[1], q[2]);
        ans[cnt++] = (q[2] - q[1] + 1) - currAns->length;
      }
    }
    return ans;
  }

private:
  Node *queryTree(int i, int l, int r, int lR, int rR)
  {
    if (lR > r || rR < l)
      return nullptr;
    if (lR <= l && r <= rR)
      return seg[i];

    int mid = l + (r - l) / 2;
    return merge(
        queryTree(2 * i + 1, l, mid, lR, rR),
        queryTree(2 * i + 2, mid + 1, r, lR, rR));
  }

  void updateTree(int i, int l, int r, int idx)
  {
    if (l == r)
    {
      arr[idx] = (arr[idx] == 'A') ? 'B' : 'A';
      seg[i] = new Node(arr[idx]);
      return;
    }

    int mid = l + (r - l) / 2;
    if (idx <= mid)
      updateTree(2 * i + 1, l, mid, idx);
    else
      updateTree(2 * i + 2, mid + 1, r, idx);

    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void build(int i, int l, int r)
  {
    if (l == r)
    {
      seg[i] = new Node(arr[l]);
      return;
    }

    int mid = l + (r - l) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid + 1, r);
    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  Node *merge(Node *l, Node *r)
  {
    if (!l)
      return r;
    if (!r)
      return l;

    int total = l->length + r->length;
    if (l->right == r->left)
      total--;

    return new Node(l->left, r->right, total);
  }
};
