#include <cstdio>
#include <algorithm>
using namespace std;
int n, aa[200000];
int main() {
  int i, j;
  scanf("%d", &n);
  if(n==1) {
    puts("0");
    return 0;
  }
  for(i=0; i<2*n; ++i) {
    scanf("%d", aa+i);
  }
  sort(aa, aa+2*n);
  long long ans = 1LL*(aa[n-1]-aa[0])*(aa[2*n-1]-aa[n]);
  long long area;
  for(i=n; i<2*n-1; ++i) {
    area = 1LL*(aa[i]-aa[0])*(aa[2*n-1]-aa[n-1]);
    if(ans > area) ans = area;
  }
  int min_w = 0x7fffffff, w;
  for(i=1; i<n; ++i) {
    w = aa[i+n-1] - aa[i];
    if(min_w > w) min_w = w;
  }
  area = 1LL*min_w*(aa[2*n-1]-aa[0]);
  if(ans > area) ans = area;
  printf("%lld\n", ans);
  return 0;
}
