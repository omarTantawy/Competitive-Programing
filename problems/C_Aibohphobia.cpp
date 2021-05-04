#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t;
string s;
int dp[6109][6109];
int solve(int l, int r) {

  if (l == r || l > r) {
    return 0;
  }
  int ans = 0;
  if (dp[l][r] != -1)
    return dp[l][r];
  if (s[l] == s[r]) {
    ans = solve(l + 1, r - 1);
  } else {
    ans = min(solve(l + 1, r), solve(l, r - 1)) + 1;
  }

  return dp[l][r] = ans;
}

int main() {
  fast_cin();
  cin >> t;
  while (t--) {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, s.length() - 1) << endl;
  }

  return 0;
}