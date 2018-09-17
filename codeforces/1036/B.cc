#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int q;
long long n, m, k;
int main() {
  scanf("%d", &q);
  while(q--) {
    scanf("%lld%lld%lld", &n,&m,&k);
    long long l, p, ans;
    l = min(n, m);
    p = max(n, m)-l;
    k-=l;
    if(k<p) {
      puts("-1");
      continue;
    }
    k-=p/2*2;
    if(p%2 == 0 && k%2 == 1) k-=2;
    if(p%2 == 1) k-=1;
    printf("%lld\n", l+k+p/2*2);
  }
  return 0;
}
