#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
  int *arr;
  int capacity;
  int topIndex;

public:
  Stack(int n)
  {
    arr = new int[n];
    capacity = n;
    topIndex = -1;
  }

  ~Stack()
  {
    delete[] arr;
  }

  void push(int val)
  {
    if (topIndex == capacity - 1)
    {
      cout << "Stack Overflow" << '\n';
      return;
    }
    arr[++topIndex] = val;
    cout << "Value Added Successfully\n";
  }

  void pop()
  {
    if (topIndex == -1)
    {
      cout << "Stack Underflow" << '\n';
      return;
    }
    --topIndex;
    cout << "Value Popped Successfully\n";
  }

  int size()
  {
    cout << (topIndex + 1) << '\n';
  }

  int top()
  {
    cout << arr[topIndex] << '\n';
  }
};

int main()
{
  int n;
  cin >> n;
  Stack st(n);

  while (1)
  {
    int option;
    cin >> option;

    if (option == 0)
      break;
    else if (option == 1)
    {
      cout << "Enter value to push into the stack : ";
      int val;
      cin >> val;
      st.push(val);
    }
    else if (option == 2)
    {
      st.pop();
    }
    else if (option == 3)
    {
      st.top();
    }
    else
    {
      st.size();
    }
  }
}