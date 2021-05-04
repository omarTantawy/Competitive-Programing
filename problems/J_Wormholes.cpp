#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1010;
const int oo = 1e9;
vector<pair<pi, int>> edges;
int cost[N], n, m;
// bellman shortest path ->weight , unweight +ve , -ve , check -ve cycles
//==========================================================================
bool bellman(int source) {
  for (int i = 1; i <= n; i++)
    cost[i] = oo;
  cost[source] = 0;
  for (int i = 1; i < n; i++) {
    bool updated = false; // bool to record if iteration made change
    for (auto edge : edges) {
      int A = edge.first.first;    // first vertex
      int B = edge.first.second;   // second vertex
      int c = edge.second;         // cost from 1st to 2nd
      if (cost[A] + c < cost[B]) { // if using this edge will make change
        cost[B] = cost[A] + c;     // change vertex cost
        updated = true;            // make true to go to second iteration
      }
    }
    if (!updated) // no change happened (optimization)
      break;
  }
  // negative cycle check
  for (auto edge : edges) {
    int A = edge.first.first;    // first vertex
    int B = edge.first.second;   // second vertex
    int c = edge.second;         // cost from 1st to 2nd
    if (cost[A] + c < cost[B]) { // if using this edge will make change
      return false;              // negative cycle found
    }
  }
  return true; // no negative cycles found
}
// end bellman
//==========================================================================

int main() {
  fast_cin();
  int t;
  cin >> t;
  while (t--) {
    edges.clear();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      ++a;
      ++b;
      edges.push_back(make_pair(make_pair(a, b), c));
    }
    if (bellman(1))
      cout << "not possible\n";
    else
      cout << "possible\n";
  }

  return 0;
}