#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 100;
const int oo = INT_MAX;
int input[N], segment_tree[N * 4];
vector<int> adj[N];
vector<pi> adj_weighted[N];
vector<pair<pi, int>> edges;
int cost[N], n, m;
// segment tree
//==========================================================================
// hints : replace + with function
void build_seg_tree(int node, int l, int r) {
  if (l == r)
    return void(segment_tree[node] = input[l]);
  int mid = (l + r) / 2;
  build_seg_tree(node * 2, l, mid), build_seg_tree(node * 2 + 1, mid + 1, r);
  segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}

int query_seg_tree(int node, int l, int r, int i, int j) {
  if (r < i || l > j)
    return 0;
  if (r <= j && l >= i)
    return segment_tree[node];
  int mid = (l + r) / 2;
  return query_seg_tree(node * 2, l, mid, i, j) +
         query_seg_tree(node * 2 + 1, mid + 1, r, i, j);
}

void update_seg_tree(int node, int l, int r, int index, int new_value) {
  if (index < l || index > r)
    return;
  if (l == r)
    return void(segment_tree[node] = new_value);
  int mid = (l + r) / 2;
  update_seg_tree(node * 2, l, mid, index, new_value),
      update_seg_tree(node * 2 + 1, mid + 1, r, index, new_value);
  segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
}
// end segment tree
//==========================================================================

// dijkstra -> weighted or unweighted , not with negative weights
//==========================================================================
void dijkstra(int source) {
  for (int i = 1; i <= n; i++)
    cost[i] = oo;   // init all costs with infinity
  cost[source] = 0; // cost to source is 0
  priority_queue<pi, vector<pi>, greater<pi>> pq; // pq sorted asc
  pq.push({0, source}); // push source node with cost 0

  while (!pq.empty()) {
    int node = pq.top().second; // get lowest cost node
    pq.pop();
    for (auto child : adj_weighted[node]) { // loop over all its children
      if (cost[node] + child.first < cost[child.second]) { // better path ?
        cost[child.second] = cost[node] + child.first;     // update cost
        pq.push({cost[child.second], child.second});       // push again to pq
      }
    }
  }
}
// end dijkstra
//==========================================================================
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

  return 0;
}