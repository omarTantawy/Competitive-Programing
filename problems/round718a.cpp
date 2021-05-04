#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 1e5;

int t;

long long n, largest = 2050e15;

int main() {
  fast_cin();

  cin >> t;

  while (t--) {
    largest = 2050e15;
    cin >> n;
    if (n < 2050 || n % 2050 != 0) {
      cout << -1 << endl;
    } else {
      long long div = 0, ans = 0;
      div = n / 2050;
      while (div != 0) {
        // cout << div % 10 << " ";
        ans += div % 10;
        div /= 10;
      }
      cout << ans << endl;
    }
  }

  return 0;
}