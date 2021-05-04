#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t, n;
string a, b;

int main() {
  fast_cin();
  cin >> t;

  while (t--) {

    cin >> n >> a >> b;
    int z = 0, o = 0, diff = -1, temp, maxx = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        diff = i;
    }

    for (int i = 0; i <= diff; i++) {
      if (a[i] == '0')
        z++;
      else
        o++;
      if (o == z)
        maxx = i;
    }

    if (a == b) {
      cout << "YES\n";
      continue;
    } else if (diff > maxx) {
      cout << "NO\n";
      continue;
    }

    bool orig = true;
    string ans = "YES";
    while (diff > 0) {
      temp = z;
      z = o;
      o = temp;
      orig = !orig;

      for (int i = diff; i >= 0; i--) {
        diff = i;
        if ((a[i] == b[i] && orig) || (a[i] != b[i] && !orig)) {
          if (b[i] == '0')
            z--;
          else
            o--;
        } else {
          break;
        }
      }

      if (z != o) {
        ans = "NO";
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}