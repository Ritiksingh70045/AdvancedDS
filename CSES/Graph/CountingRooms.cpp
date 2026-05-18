#include <bits/stdc++.h>
using namespace std;

vector<int> drow = {1, 0, -1, 0};
vector<int> dcol = {0, 1, 0, -1};

void solve(int row, int col,
           vector<vector<char>> &grid,
           vector<vector<int>> &vis)
{
  int n = grid.size();
  int m = grid[0].size();

  queue<pair<int, int>> q;
  q.push({row, col});
  vis[row][col] = 1;

  while (!q.empty())
  {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int dr = r + drow[i];
      int dc = c + dcol[i];

      if (dr >= 0 && dr < n &&
          dc >= 0 && dc < m &&
          !vis[dr][dc] &&
          grid[dr][dc] == '.')
      {
        q.push({dr, dc});
        vis[dr][dc] = 1;
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> vis(n, vector<int>(m, 0));

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '.' && !vis[i][j])
      {
        count++;
        solve(i, j, grid, vis);
      }
    }
  }

  cout << count;
}