#include <bits/stdc++.h>
using namespace std;

class PainterPartition
{
public:
  int countPainters(vector<int> &boards, int time)
  {
    int painters = 1;
    long long boardsPainter = 0;

    for (int i = 0; i < boards.size(); i++)
    {
      if (boardsPainter + boards[i] <= time)
      {
        boardsPainter += boards[i];
      }
      else
      {
        painters++;
        boardsPainter = boards[i];
      }
    }

    return painters;
  }

  int findLargestMinDistance(vector<int> &boards, int k)
  {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int result = high;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      int painters = countPainters(boards, mid);

      if (painters > k)
      {
        low = mid + 1;
      }
      else
      {
        result = mid;
        high = mid - 1;
      }
    }

    return result;
  }
};

int main()
{
  vector<int> boards = {10, 20, 30, 40};
  int k = 2;

  PainterPartition pp;
  int ans = pp.findLargestMinDistance(boards, k);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
