#include <cstdio>
using namespace std;
bool chk(int n) {
  int s=0;
  while(n) {
    s += n%10;
    n/=10;
  }
  return s%4 == 0;
}
int main() {
  int a;
  scanf("%d", &a);
  for(; !chk(a); ++a);
  printf("%d", a);

  return 0;
}
