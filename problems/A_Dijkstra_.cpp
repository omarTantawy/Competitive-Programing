#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pi;
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1e5 + 10;
const int oo = INT_MAX;
vector<pi> adj_weighted[N];
long long n, m;
pair<long long, int> cost[N];
stack<int> ans;
// dijkstra -> weighted or unweighted , not with negative weights
//==========================================================================
void dijkstra(int source) {
  for (int i = 1; i <= n; i++)
    cost[i].first = 1e15; // init all costs with infinity
  cost[source].first = 0; // cost to source is 0
  priority_queue<pi, vector<pi>, greater<pi>> pq; // pq sorted asc
  pq.push({0, source}); // push source node with cost 0
  while (!pq.empty()) {
    int node = pq.top().second; // get lowest cost node
    // int c = cost[node].first;
    pq.pop();
    for (auto child : adj_weighted[node]) { // loop over all its children
      if (cost[node].first + child.first <
          cost[child.second].first) { // better path to child?
        cost[child.second].first =
            cost[node].first + child.first; // update cost
        cost[child.second].second = node;
        pq.push({cost[child.second].first, child.second}); // push again to pq
      }
    }
  }
}
// end dijkstra
//==========================================================================

int main() {
  fast_cin();
  int a, b, c;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    adj_weighted[a].push_back(make_pair(c, b));
    adj_weighted[b].push_back(make_pair(c, a));
  }
  dijkstra(1);
  int curr = n;
  while (curr != 0) {
    ans.push(curr);
    curr = cost[curr].second;
  }
  if (cost[n].first != 1e15)
    while (!ans.empty()) {
      cout << ans.top() << " ";
      ans.pop();
    }
  else
    cout << -1;

  return 0;
}