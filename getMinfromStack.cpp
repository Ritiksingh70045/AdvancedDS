class SpecialStack
{
  stack<int> st;
  stack<int> minSt;

public:
  SpecialStack() {}

  void push(int x)
  {
    st.push(x);

    if (minSt.empty() || x <= minSt.top())
    {
      minSt.push(x);
    }
  }

  void pop()
  {
    if (st.empty())
      return;

    if (st.top() == minSt.top())
    {
      minSt.pop();
    }
    st.pop();
  }

  int peek()
  {
    if (st.empty())
      return -1;
    return st.top();
  }

  bool isEmpty()
  {
    return st.empty();
  }

  int getMin()
  {
    if (minSt.empty())
      return -1;
    return minSt.top();
  }
};