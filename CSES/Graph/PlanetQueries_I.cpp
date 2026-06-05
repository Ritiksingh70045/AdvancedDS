#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
const int LOG = 30;
int up[MAXN][LOG];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  // 1-step jump
  for (int i = 1; i <= n; i++)
  {
    cin >> up[i][0];
  }

  // Binary Lifting Table
  for (int j = 1; j < LOG; j++)
  {
    for (int node = 1; node <= n; node++)
    {
      up[node][j] = up[up[node][j - 1]][j - 1];
    }
  }

  while (q--)
  {
    int x;
    int k;

    cin >> x >> k;

    for (int j = 0; j < LOG; j++)
    {
      if (k & (1 << j))
      {
        x = up[x][j];
      }
    }

    cout << x << '\n';
  }

  return 0;
}