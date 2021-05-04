#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

const int N = 2e5 + 9;
int n, arr[N];

int main() {
  fast_cin();

  cin >> n;

  for (int i = 1; i < n; i++)
    cin >> arr[i];

  int left = 1, right = 2, ans = 1;

  while (left != n) {

    int temp = 1;
    bool used = false;
    for (int i = right; i < n; i++) {

      if (arr[i + 1] < arr[left]) {
        if ((arr[i + 2] > arr[left] && !used)) {
          used = true;
          i++;
        } else if (arr[left]) {
        }
      }
    }
  }

  return 0;
}