#include <cstdio>
using namespace std;
int main() {
  int i;
  int n, a[400000];
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    scanf("%d", a+i);
    a[i+n] = a[i];
  }
  int ans = 0, k = 0;
  for(i=0; i<2*n; ++i) {
    if(a[i] == 0) {
      if(ans < k) {
        ans = k;
      }
      k = 0;
    }
    else ++k;
  }
  printf("%d", ans);
  return 0;
}
