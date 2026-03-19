#include <iostream>
#include <thread>
using namespace std;

bool flag[2] = {false, false};
int turn = 0;
void process(int i)
{
  int j = 1 - i;

  flag[i] = true;
  turn = j;

  while (flag[j] && turn == j)
  {
    // busy waiting (spin lock)
  }

  cout << "Process " << i << " is in critical section\n";

  flag[i] = false;

  cout << "Process " << i << " is in remainder section\n";
}

int main()
{
  thread t1(process, 0);
  thread t2(process, 1);

  t1.join();
  t2.join();

  return 0;
}