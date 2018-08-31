#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
  LL t;
  while(b) {
    t=a;a=b;b=t%b;
  }
  return a;
}
LL lcm(LL a, LL b) {
  return a*b/gcd(a,b);
}
int n;
int main() {
  int i;
  scanf("%d", &n);
  LL ans = 0;
  int x, y;
  for(i=0; i<n; ++i) {
    scanf("%d%d", &x,&y);
    ans = gcd(lcm(x,y), ans);
  }
  if(ans > 1) {
    for(i=2; i<=44721; ++i) {
      if(ans%i == 0) {
        break;
      }
    }
    if(i>44721) {
      i = max(gcd(ans, x), gcd(ans, y));
    }
  } else i=-1;
  printf("%d", i);
  return 0;
}
