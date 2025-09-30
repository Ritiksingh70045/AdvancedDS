int solve(vector<int> &A, int B)
{
  sort(A.begin(), A.end());
  int max1 = A[A.size() - 1];
  int max2 = A[A.size() - 2];

  int pair_damage = max1 + max2;
  int moves = (B / pair_damage) * 2;
  int rem = B % pair_damage;

  if (rem == 0)
    return moves;
  else if (rem <= max1)
    return moves + 1;
  else
    return moves + 2;
}


#include <queue>
#include <unordered_set>
using namespace std;

int solve(int A) {
    if (A == 1) return 0;

    // Each state is (lines on screen, clipboard lines)
    queue<tuple<int, int, int>> q; // (lines, clipboard, energy)
    unordered_set<string> visited;

    q.push({1, 0, 0});

    while (!q.empty()) {
        auto [lines, clip, energy] = q.front(); q.pop();

        if (lines == A) return energy;

        string state = to_string(lines) + "-" + to_string(clip);
        if (visited.count(state)) continue;
        visited.insert(state);

        // 1. CTRL+A + Copy (new clipboard = lines), cost +1
        q.push({lines, lines, energy + 1});

        // 2. Paste clipboard, if clipboard > 0 (free operation)
        if (clip > 0 && lines + clip <= A)
            q.push({lines + clip, clip, energy + 1});
    }

    return -1; // Should not reach here
}
