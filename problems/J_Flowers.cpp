// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1e5 + 9;
long long mem[N], t, k, a, b, MOD = 1e9 + 7;
long long solve(int len) {
  if (len < 0)
    return 0;
  if (len == 0)
    return 0;

  long long &ret = mem[len];

  if (ret != -1)
    return ret;

  return ret = (solve(len - 1) + solve(len - k)) % MOD;
}

int main() {
  fast_cin();

  memset(mem, -1, sizeof(mem));
  cin >> t >> k;

  solve(N - 4);

  for (int i = 1; i < N; i++) {
    mem[i] += mem[i - 1];
    mem[i] %= MOD;
  }

  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    cout << mem[b] - mem[a - 1] << endl;
  }
  return 0;
}