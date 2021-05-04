#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

// value,remaining_wight
const int N = 109, oo = 0x3f3f3f, M = 1e5 + 5;
long long n, W, val[N], wei[N], mem[N][M];

long long solve(int idx, int value) {

  if (value <= 0)
    return 0;
  if (idx < 0)
    return oo;

  long long &ret = mem[idx][value];
  if (ret != -1)
    return ret;

  ret = oo;
  long long mchoice1 = solve(idx - 1, value - val[idx]) + wei[idx];
  long long mleave = solve(idx - 1, value);

  ret = min(ret, min(mchoice1, mleave));
  return ret;
}

int main() {
  fast_cin();

  cin >> n >> W;

  for (int i = 0; i < n; i++) {
    cin >> val[i] >> wei[i];
  }
  memset(mem, -1, sizeof(mem));

  for (int val = 100009; val >= 0; --val) {
    if (solve(n - 1, val) <= W) {
      cout << val;
      return 0;
    }
  }

  //   cout << val;
  return 0;
}