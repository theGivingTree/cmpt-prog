#include <cstdio>
#include <climits>
using namespace std;
using LL = long long;
LL H;
LL da[200001], mlo = LLONG_MAX;
int n;
int main() {
  int i, j;
  scanf("%lld %d", &H, &n);
  for(i=1; i<=n; ++i) {
    scanf("%lld", da+i);
    da[i] += da[i-1];
    if(mlo > da[i]) mlo = da[i];
  }
  if(H + mlo > 0 && da[n] >= 0) {
    printf("-1");
    return 0;
  }

  LL rc, hh;
  if(H + mlo <= 0) {
    rc = 0;
    hh = H;
  }
  else {
    rc = (H + mlo - 1) / (-da[n]) + 1;
    hh = H + rc * da[n];
  }
  for(i=1; hh + da[i] > 0; ++i);
  printf("%lld", rc*n+i);
  return 0;
}
