#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
int n, aa[1000001], bb[1000001];
LL tot;
LL totalgr[2];
int main() {
  int i, j; 
  scanf("%d", &n);

  for(i=0; i<n; ++i) {
    scanf("%d", aa+i);
    tot += aa[i];
  }
  for(i=0; i<n; ++i) {
    scanf("%d", bb+i);
    tot += bb[i];
  }
  for(i=0; i<n; ++i) {
    totalgr[0] += 1LL*i*aa[i];
    totalgr[0] += 1LL*(2*n-1-i)*bb[i];
  }
  for(i=0; i<n; ++i) {
    totalgr[1] += 1LL*i*bb[i];
    totalgr[1] += 1LL*(2*n-1-i)*aa[i];
  }

  LL ans = 0;
  LL yo = 0, ko = 0;
  for(i=0; i<n; ++i) {
    ko = totalgr[0];
    if(i&1) ko = totalgr[1];
    if(ans < yo + ko) ans = yo + ko;

    int a=aa[i], b=bb[i];
    if(i&1) swap(a, b);
    yo += (i*2LL)*a + (i*2LL+1)*b;
    tot -= aa[i] + bb[i];
    totalgr[0] += tot;
    totalgr[0] -= (2LL*i)*aa[i] + (2LL*n-1)*bb[i];
    totalgr[1] += tot;
    totalgr[1] -= (2LL*i)*bb[i] + (2LL*n-1)*aa[i];
  }

  printf("%lld\n", ans);
  return 0;
}
