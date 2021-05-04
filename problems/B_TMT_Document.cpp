#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t, n, temp;
string s;
int main() {
  fast_cin();

  cin >> t;

  while (t--) {
    cin >> n >> s;
    int t = 0, m = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'M')
        m++;
      else
        t++;
    }

    if (t != m * 2) {
      cout << "NO\n";
      continue;
    }
    t = 0;
    m = 0;
    string ans = "YES\n";
    for (int i = 0; i < n; i++) {
      if (s[i] == 'M') {
        ++m;
        if (m > t) {
          ans = "NO\n";
          break;
        }
        --t;
        --m;
      } else {
        ++t;
      }
    }
    t = 0;
    m = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'M') {
        ++m;
        if (m > t) {
          ans = "NO\n";
          break;
        }
        --t;
        --m;
      } else {
        ++t;
      }
    }

    cout << ans;
  }

  return 0;
}

//   if (minn - 1 > -1 && maxx + 1 < n) {
//     if (vec[maxx + 1] - vec[minn] < vec[maxx] - vec[minn - 1]) {
//       ans += vec[maxx + 1] - vec[minn];
//       ++maxx;
//     } else {
//       ans += vec[maxx] - vec[minn - 1];
//       --minn;
//     }
//   } else if (minn - 1 > -1) {
//     ans += vec[maxx] - vec[minn - 1];
//     --minn;
//   } else {
//     ans += vec[maxx + 1] - vec[minn];
//     ++maxx;
//   }
// }
//   while (cnt != n) {
//     cnt++;
//     if (minn - 1 > -1 && maxx + 1 < n) {
//       if (vec[maxx + 1] - vec[minn] < vec[maxx] - vec[minn - 1]) {
//         ans += vec[maxx + 1] - vec[minn];
//         ++maxx;
//       } else {
//         ans += vec[maxx] - vec[minn - 1];
//         --minn;
//       }
//     } else if (minn - 1 > -1) {
//       ans += vec[maxx] - vec[minn - 1];
//       --minn;
//     } else {
//       ans += vec[maxx + 1] - vec[minn];
//       ++maxx;
//     }
//   }

//   cur = (n / 2) + 1, maxx = cur, minn = cur, cnt = 1;
//   while (cnt != n) {
//     cnt++;
//     if (minn - 1 > -1 && maxx + 1 < n) {
//       if (vec[maxx + 1] - vec[minn] < vec[maxx] - vec[minn - 1]) {
//         ans2 += vec[maxx + 1] - vec[minn];
//         ++maxx;
//       } else {
//         ans2 += vec[maxx] - vec[minn - 1];
//         --minn;
//       }
//     } else if (minn - 1 > -1) {
//       ans2 += vec[maxx] - vec[minn - 1];
//       --minn;
//     } else {
//       ans2 += vec[maxx + 1] - vec[minn];
//       ++maxx;
//     }
//   }