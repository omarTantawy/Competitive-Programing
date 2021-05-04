#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
struct stat info;

int main() {
  char s1[100], s2[100];
  cout << "enter first path : ";
  scanf_s("%s", &s1);
  cout << "enter second path : ";
  scanf_s("%s", s2);

  if (stat(s1, &info) != 0)
    printf("cannot access %s\n", s1);
  else if (info.st_mode & S_IFDIR) // S_ISDIR() doesn't exist on my windows
    printf("%s is a directory\n", s1);
  else
    printf("%s is no directory\n", s1);
}