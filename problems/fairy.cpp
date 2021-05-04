#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t, l, m;
queue<int> left1, right1;

queue<int> lr[2];
string s;
int temp;
int main() {
  fast_cin();

  cin >> t;
  while (t--) {
    cin >> l >> m;
    l *= 100;
    for (int i = 0; i < m; i++) {
      cin >> temp >> s;
      if (s == "left") {
        left1.push(temp);
      } else {
        right1.push(temp);
      }
    }

    // mash mohm

    // 3zizin nshil redundant code
    // azai ?
    int pos = 0;
    int ans = 0;
    while (!left1.empty() && !right1.empty()) {
      int current = 0;

      while (!lr[pos].empty() && current + !lr[pos].front() <= l) {
        current += lr[pos].front();
        lr[pos].pop();
      }

      //   if (pos == 0) {
      //     while (!left1.empty() && current + left1.front() <= l) {
      //       current += left1.front();
      //       left1.pop();
      //     }

      //   } else {
      //     while (!right1.empty() && current + right1.front() <= l) {
      //       current += right1.front();
      //       right1.pop();
      //     }
      //   }

      ans++;
      pos = ~pos;
    }

    cout << ans << endl;

    return 0;
  }
