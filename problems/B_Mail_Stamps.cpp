#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1e5 + 5;
int n, x, y;
map<int, bool> v;
vector<int> path;
map<int, vector<int>> adj;

void dfs(int s) {
  v[s] = 1;
  path.push_back(s);
  for (auto it : adj[s]) {
    if (!v[it]) {
      dfs(it);
    }
  }
}

int main() {
  fast_cin();

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int start = 0;

  for (auto it : adj) {
    if (it.second.size() == 1) {
      start = it.first;
      break;
    }
  }
  dfs(start);

  for (auto it : path) {
    cout << it << " ";
  }

  return 0;
}