#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 5e5 + 5;
int n, m, temp, t2;
vector<int> adj[N];
bool v[N];
vector<int> group;
int ans[N];
void dfs(int node) {
  v[node] = 1;
  group.push_back(node);
  for (auto adjn : adj[node]) {
    if (!v[adjn]) {
      dfs(adjn);
    }
  }
}

void bfs(int node) {
  queue<int> q;
  q.push(node);
  v[node] = 1;
  group.push_back(node);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto it : adj[cur]) {
      if (!v[it]) {
        group.push_back(it);
        q.push(it);
        v[it] = 1;
      }
    }
  }
}

int main() {
  fast_cin();

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    if (temp == 0)
      continue;
    int user;
    cin >> user;
    for (int j = 1; j < temp; j++) {
      cin >> t2;
      adj[user].push_back(t2);
      adj[t2].push_back(user);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!v[i]) {
      bfs(i);
      for (auto it : group)
        ans[it] = group.size();
      group.clear();
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";

  return 0;
}