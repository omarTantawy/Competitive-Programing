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
vector<int> adj_graph[N];
bool visited_nodes[N];
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
// dfs
// O(V+E)
// apps : connected components , lexic shortest path , time in and out , get
// ancestors
// can't : shortest path
//==========================================================================
void dfs(int current_node, int parent = 0) {      // takes source
  visited_nodes[current_node] = true;             // mark visited
  for (auto adj_node : adj_graph[current_node]) { // loop over children
    if (!visited_nodes[adj_node]) {               // if not visited before
      dfs(adj_node, current_node);                // dfs into it
    }
  }
}
// end dfs
//==========================================================================
// bfs
// O(V+E)
// apps : connected components , shortest path
// can't :
//==========================================================================
void bfs(int node) {                     // takes source
  visited_nodes[node] = true;            // mark visited
  queue<int> q;                          // to check children queue
  q.push(node);                          // push sourse
  while (!q.empty()) {                   // while no children to check
    node = q.front();                    // get top node
    q.pop();                             // remove it
    for (auto child : adj_graph[node]) { // loop over all its children
      if (!visited_nodes[child]) {       // if not visited before
        q.push(child);                   // push to check its neighbours
        visited_nodes[child] = true;     // mark visited to avoid visting again
      }
    }
  }
}
// end bfs
//==========================================================================
//start topological sort
// O(V+E)
// replace max with problem
//==========================================================================
int topological(pi node){ // called with {source , 0}
  if(visited_nodes[node.first])// if this node is visted before
    return ans[node.first]; // return saved answer
  vis[node.first] = true; // mark visited
  for(auto child : adj_weighted[node.first]){ // loop over its children
    ans[node.first] = max(ans[node.first] , dfs(child)); // get max value path (dep on problem)
  }
  ans[node] += node.second; // add my time to reach me
  return ans[node]; // return ans 
}
//end topological sort
//==========================================================================
// dfs a tree
// O(V+E)
//==========================================================================
int timer =0;
void dfs_tree(int current_node, int parent = 0) {      // takes source
  in[current_node] = ++timer;
  for (auto adj_node : adj_graph[current_node]) { // loop over children
    if (adj_node  != parent) {               // if not visited before
      dfs_tree(adj_node, current_node);                // dfs into it
    }
  }
  out[current_node] = timer;
}
// end dfs
//==========================================================================

int main() {
  fast_cin();

  return 0;
}