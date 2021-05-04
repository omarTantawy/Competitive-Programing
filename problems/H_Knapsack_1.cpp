#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// value,remaining_wight
const int N = 109;
int n, W, v[N], w[N];

int solve() {}

int main() {
  fast_cin();

  cin >> n >> W;

  for (int i = 0; i < n; i++) {
    cin >> v[i] >> w[i];
  }
  solve(0, w);
  return 0;
}