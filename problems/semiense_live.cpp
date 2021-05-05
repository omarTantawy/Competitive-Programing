class A {
public:
  A() {
    std::cout << “A cstr”<< std::endl;
    x = 5;
  }
  virtual ~A() { std::cout << “A dstr” << std::endl; }

  Virtual void funct();

private:
  Int x;
};

class B : public A {
public:
  B() { std::cout << “B cstr” << std::endl; }
  ~B() { std::cout << “B dstr” << std::endl; }

  void funct();
};

int main(void) {
  A *a = new B();
  a->funct();
  delete a;
}

A cstr

    B cstr B dstr

    int
    sumOdd(const vector<int> &input) {

  if (input == NULL) {
    Throw 1234;
  }
  if (input.size() < count) {
    Throw 2345;
  }
  if (count == 0)
    return 0;
  Int ans = 0;
  for (int *i = input; i < input + count; i++) {
    if (*i % 2 != 0) {
      ans += *i;
    }
  }
  Return ans;
}

Int main() {

  vector<int> mvec;
  mvec.push_back(1);
  sumOdd(mvec);
}

vector<int> get_substrings(string s) {
  Int start[26], end[26];
  for (int = 0; i < 26; i++) {
    Start[i] = -1;
    End[i] = -1;
  }
  for (int i = 0; i < s.size(); i++) {
    if (start[s[i] - ‘a’ ] == -1) {
      start[s[i] - ‘a’] = i;
      end[s[i] -’a’] = i;
    }
    Else end[s[i] -’a’] = i;
  }
  // abdjfhdjfabllllllllllllllllllll
  vector<int> ans;
  Int curr_max = 0;
  Int end = 0;
  for (int i = 0; i < s.size(); i++) {
    curr_max = end[s[i] - ‘a’ ]; // 8
    Int len = 1 for (int j = start[s[i] -’a’ ]; j <= curr_max; j++) {
      Curr_max = max(curr_max, end[s[j] -’a’]);
      Len++;
      if (j == curr_max) {
        I = j - 1;
      }
    }
    Ans.push_back(len);
  }
