#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Stack
{
private:
  int arr[1000];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  bool isEmpty()
  {
    return top == -1;
  }

  void push(int x)
  {
    arr[++top] = x;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow\n";
      return -1;
    }
    return arr[top--];
  }

  int peek()
  {
    if (isEmpty())
      return -1;
    return arr[top];
  }

  int evaluate(string postfix)
  {
    for (char ch : postfix)
    {
      if (ch == ' ')
        continue;

      if (isdigit(ch))
      {
        push(ch - '0');
      }
      else
      {
        int operand2 = pop();
        int operand1 = pop();

        switch (ch)
        {
        case '+':
          push(operand1 + operand2);
          break;

        case '-':
          push(operand1 - operand2);
          break;

        case '*':
          push(operand1 * operand2);
          break;

        case '/':
          push(operand1 / operand2);
          break;

        case '%':
          push(operand1 % operand2);
          break;
        }
      }
    }

    return pop();
  }
};

int main()
{
  Stack st;

  string postfix = "23*54*+9-";

  cout << "Result = " << st.evaluate(postfix);

  return 0;
}