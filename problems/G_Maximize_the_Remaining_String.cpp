#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

int t;
string s;

int main() {
  fast_cin();
  cin >> t;

  while (t--) {

    cin >> s;
    bool pal = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != 'a')
        pal = true;
    }
    if (!pal) {
      cout << "NO\n";
      continue;
    }

    string temp2 = 'a' + s;
    string temp = 'a' + s;
    reverse(temp.begin(), temp.end());
    if (temp != temp2) {
      cout << temp << endl;
      continue;
    }
  }

  return 0;
}