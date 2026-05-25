#include <bits/stdc++.h>
using namespace std;
// MultiSource BFS
bool isBoundary(int row, int col, int n, int m)
{
  return (row == 0 || row == n - 1 || col == 0 || col == m - 1);
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));
  vector<vector<int>> userTime(n, vector<int>(m, 1e9));

  queue<pair<int, int>> monsterQ;
  queue<pair<int, int>> userQ;

  int sr, sc;

  // INPUT

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];

      if (grid[i][j] == 'M')
      {
        monsterQ.push({i, j});
        monsterTime[i][j] = 0;
      }

      else if (grid[i][j] == 'A')
      {
        sr = i;
        sc = j;

        userQ.push({i, j});
        userTime[i][j] = 0;
      }
    }
  }

  vector<int> drow = {0, 1, 0, -1};
  vector<int> dcol = {1, 0, -1, 0};

  vector<char> direction = {'R', 'D', 'L', 'U'};

  // ================= MONSTER BFS =================

  while (!monsterQ.empty())
  {
    int row = monsterQ.front().first;
    int col = monsterQ.front().second;

    monsterQ.pop();

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (nrow >= 0 && nrow < n &&
          ncol >= 0 && ncol < m &&
          grid[nrow][ncol] != '#' &&
          monsterTime[row][col] + 1 < monsterTime[nrow][ncol])
      {
        monsterTime[nrow][ncol] = monsterTime[row][col] + 1;

        monsterQ.push({nrow, ncol});
      }
    }
  }

  // ================= USER BFS =================

  vector<vector<pair<int, int>>> parent(
      n,
      vector<pair<int, int>>(m, {-1, -1}));

  vector<vector<char>> moveTaken(n, vector<char>(m));

  int dr = -1;
  int dc = -1;

  while (!userQ.empty())
  {
    int row = userQ.front().first;
    int col = userQ.front().second;

    userQ.pop();

    if (isBoundary(row, col, n, m))
    {
      dr = row;
      dc = col;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (nrow >= 0 && nrow < n &&
          ncol >= 0 && ncol < m &&
          grid[nrow][ncol] != '#' &&
          userTime[row][col] + 1 < monsterTime[nrow][ncol] &&
          userTime[row][col] + 1 < userTime[nrow][ncol])
      {
        userTime[nrow][ncol] = userTime[row][col] + 1;

        parent[nrow][ncol] = {row, col};

        moveTaken[nrow][ncol] = direction[i];

        userQ.push({nrow, ncol});
      }
    }
  }

  // ================= OUTPUT =================

  if (dr == -1)
  {
    cout << "NO";
  }
  else
  {
    cout << "YES" << '\n';

    vector<char> path;

    while (!(dr == sr && dc == sc))
    {
      path.push_back(moveTaken[dr][dc]);

      int pr = parent[dr][dc].first;
      int pc = parent[dr][dc].second;

      dr = pr;
      dc = pc;
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (char ch : path)
      cout << ch;
  }

  return 0;
}