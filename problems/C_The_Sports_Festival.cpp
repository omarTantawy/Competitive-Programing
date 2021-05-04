#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
typedef long long ll;
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 2005;
int n, temp;
vector<int> vec;
ll dp[N][N];
ll solve(int l, int r) {
  if (l == r)
    return 0;

  if (dp[l][r] != -1)
    return dp[l][r];

  return dp[l][r] = vec[r] - vec[l] + min(solve(l + 1, r), solve(l, r - 1));
}

int main() {
  fast_cin();
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n - 1);

  return 0;
}