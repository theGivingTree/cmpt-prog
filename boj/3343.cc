#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
  int gcd(int a, int b) {
    int t;
    while(b) {
      t=b;
      b=a%b;
      a=t;
    }
    return a;
  }
int main() {
  int a,b,c,d;
  long long n, ans, e, f;
  scanf("%lld%d%d%d%d",&n,&a,&b,&c,&d);
  if(1LL*a*d<1LL*c*b) {
    swap(a, c), swap(b, d);
  }
  e = (n+a-1)/a;
  f = 0;
  ans = LLONG_MAX;
  int x = a < c ? c: a;
  x/=gcd(a,c);
  for(int i=0; i<x && e>=0;) {
    long long y = e*b + f*d;
    if(ans > y) {
      ans = y;
    }
    --e, ++i;
    while(e*a + f*c < n) ++f;
    while((e-1)*a + f*c >= n) --e, ++i;
  }
  printf("%lld", ans);
  return 0;
}
