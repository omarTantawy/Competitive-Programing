// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1e5 + 9;
int n, a[N], b[N], c[N], mem[N][N];
int solve(int idx, int pre) {

  if (idx == n)
    return 0;

  int &ret = mem[idx][pre];

  if (ret != -1)
    return ret;

  if (pre == 0) {
    ret = max(ret, a[idx] + solve(idx + 1, 1));
    ret = max(ret, a[idx] + solve(idx + 1, 2));
  }
  if (pre == 1) {
    ret = max(ret, b[idx] + solve(idx + 1, 0));
    ret = max(ret, b[idx] + solve(idx + 1, 2));
  }

  if (pre == 2) {
    ret = max(ret, c[idx] + solve(idx + 1, 0));
    ret = max(ret, c[idx] + solve(idx + 1, 1));
  }
  return ret;
}

int main() {
  fast_cin();
  cin >> n;
  memset(mem, -1, sizeof(mem));
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  int ans = -1;
  for (int i = 0; i < 3; i++)
    ans = max(ans, solve(0, i));

  return 0;
}