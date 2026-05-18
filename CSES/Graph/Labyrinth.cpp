#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
  vector<vector<char>> moveTaken(n, vector<char>(m));

  int sr, sc, dr, dc;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];

      if (grid[i][j] == 'A')
      {
        sr = i;
        sc = j;
      }
      else if (grid[i][j] == 'B')
      {
        dr = i;
        dc = j;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = 1;

  vector<int> drow = {1, 0, -1, 0};
  vector<int> dcol = {0, -1, 0, 1};
  vector<char> dir = {'D', 'L', 'U', 'R'};

  while (!q.empty())
  {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = row + drow[i];
      int nc = col + dcol[i];

      if (nr >= 0 && nr < n &&
          nc >= 0 && nc < m &&
          !vis[nr][nc] &&
          grid[nr][nc] != '#')
      {
        vis[nr][nc] = 1;
        parent[nr][nc] = {row, col};
        moveTaken[nr][nc] = dir[i];
        q.push({nr, nc});
      }
    }
  }

  if (!vis[dr][dc])
  {
    cout << "NO\n";
    return 0;
  }

  string path;

  int r = dr, c = dc;

  while (r != sr || c != sc)
  {
    path.push_back(moveTaken[r][c]);
    auto p = parent[r][c];
    r = p.first;
    c = p.second;
  }

  reverse(path.begin(), path.end());

  cout << "YES\n";
  cout << path.size() << '\n';
  cout << path << '\n';
}