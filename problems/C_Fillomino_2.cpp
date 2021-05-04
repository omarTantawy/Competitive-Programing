#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 510;
int l = 0, n, temp, grid[N][N];

bool valid(int r, int c) {
  if (c <= 0 || r > n || grid[r][c] != 0)
    return false;
  return true;
}
void fill(int cur, int r, int c) {
  grid[r][c] = cur;
  --l;
  if (valid(r, c - 1) && l) {
    fill(cur, r, c - 1);
  }
  if (valid(r + 1, c) && l) {
    fill(cur, r + 1, c);
  }
}
int main() {
  fast_cin();

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> temp;
    grid[i][i] = temp;
  }

  for (int i = 1; i <= n; i++) {
    int cur = grid[i][i];
    l = cur;
    fill(cur, i, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j <= i)
        cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}