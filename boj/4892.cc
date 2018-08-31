#include <cstdio>
using namespace std;
int main() {
  int i=1, n;
  while(scanf("%d", &n), n) {
    printf("%d. %s %d\n", i, n&1?"odd":"even", (3*n+1)/6);
    ++i;
  }
}
