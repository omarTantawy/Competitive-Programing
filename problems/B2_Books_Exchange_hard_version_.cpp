#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 2e5 + 5;
int t, n, a[N], ans[N];
vector<int> group;

int main() {
  fast_cin();

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
      group.clear();
      if (ans[i] == 0) {
        group.push_back(i);
        int cur = a[i];
        while (cur != i) {
          group.push_back(cur);
          cur = a[cur];
        }
        for (auto it : group) {
          ans[it] = group.size();
        }
      }

      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}