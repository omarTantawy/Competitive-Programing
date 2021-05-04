#include <bits/stdc++.h>
using namespace std;
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

class m {

public:
  void function1() { cout << "function1\n"; }
  virtual void function2() {}
};

class m2 : public m {
public:
  void function2() { cout << "function 2 overriden\n"; }
};

int main() {
  fast_cin();

  m2 m;
  m.function2();

  map<string, int> mmap;
  // mutex::lock mu;
  vector<string> a = {"a", "a", "b", "c", "d"};

  return 0;
}