#include <cstdio>
#include <algorithm>
using namespace std;
int test_case=0, n;
int a, b, c;
int A, B, C;
int main() {
  while(scanf("%d", &n), ++test_case, n) {
    A=B=C=0;
    for(int i=0; i<n; ++i) {
      scanf("%d %d %d", &a, &b, &c);
      a += min({A, B});
      b += min({a, A, B, C});
      c += min({b, B, C});
      A = a, B = b, C = c;
    }
    printf("%d. %d\n", test_case, B);
  }
  return 0;
}
