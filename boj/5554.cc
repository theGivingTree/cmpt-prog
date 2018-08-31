#include <cstdio>
using namespace std;
int main() {
  int a, b=0;
  while(~scanf("%d", &a)) b+=a;
  printf("%d\n%d", b/60, b%60);
  return 0;
}
