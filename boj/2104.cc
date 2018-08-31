#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
int N, aa[100000];
LL go(int a, int b) {
  if(a==b) return 1LL*aa[a]*aa[a];

  int i, j, m = (a+b)/2;
  i=m, j=m+1;
  LL cmin, x=0, y=0;
  while(a<=i || j<=b) {
    if(j>b || a<=i && aa[i] > aa[j]) {
      cmin = aa[i];
      for(; a<=i && aa[i]>=cmin; --i) x+=aa[i];
    }
    else {
      cmin = aa[j];
      for(; j<=b && aa[j]>=cmin; ++j) x+=aa[j];
    }
    if(y < x*cmin) y = x*cmin;
  }
  return max({go(a, m), go(m+1, b), y});
}
int main() {
  int i;
  scanf("%d", &N);
  for(i=0; i<N; ++i) scanf("%d", &aa[i]);
  printf("%lld", go(0, N-1));
  return 0;
}
