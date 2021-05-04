#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 110;
priority_queue<int, vector<int>, greater<int>> pq[N];
int t, n, m, temp, ans[N][N];

int main() {
  fast_cin();

  cin >> t;

  while (t--) {
    cin >> n >> m;

    // for (int i = 0; i < n; i++) {
    //   pq[i].clear();
    // }

    memset(ans, 0, sizeof ans);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> temp;
        pq[i].push(temp);
      }
    }

    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << pq[i].top();
    //     pq[i].pop();
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < m; i++) {
      int mini = 1e9 + 20, min_index = 0;
      for (int j = 0; j < n; j++) {
        if (!pq[j].empty() && pq[j].top() < mini) {
          mini = pq[j].top();
          min_index = j;
        }
      }
      pq[min_index].pop();
      ans[min_index][i] = mini;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ans[i][j] == 0) {
          ans[i][j] = pq[i].top();
          pq[i].pop();
        }
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}