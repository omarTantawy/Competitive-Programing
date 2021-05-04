#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t, n, temp;
vector<int> vec, o, e;
int main() {
  fast_cin();

  cin >> t;

  while (t--) {
    o.clear();
    e.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      if (temp % 2 == 0)
        e.push_back(temp);
      else
        o.push_back(temp);
    }

    for (int i = 0; i < o.size(); i++)
      cout << o[i] << " ";
    for (int i = 0; i < e.size(); i++)
      cout << e[i] << " ";
    cout << endl;
  }

  return 0;
}