#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
using namespace std;
using LL = long long;
int n;
int xx, yy, c;
int main() {
  int i, j;
  scanf("%d", &n);
  LL qd = 0;
  LL ans = LLONG_MAX, ans2 = LLONG_MAX;
  LL x, y, px, py;
  for(i=0; i<n; ++i) {
    LL qq = 0;
    scanf("%lld%lld",&x,&y);
    if(x==0 && y==0) continue;
    qq = x*x+y*y;
    if(qd < qq) {
      c=1;
      ans2 = LLONG_MAX;
      ans = LLONG_MAX;
      qd = qq;
      px = xx = x;
      py = yy = y;
    }
    else if(qd == qq) {
      ++c;
      LL aaa = px*x + py*y;
      if(px*y - py*x < 0) ans2 = aaa;
      else if(ans > aaa) ans = aaa;
      px = x;
      py = y;
    }
  }
  if(c == 1) {
    puts("360");
    exit(0);
  }
  LL aaa = px*xx + py*yy;
  if(px*yy - py*xx < 0) ans2 = aaa;
  else if(ans > aaa) ans = aaa;
  if(ans2 != LLONG_MAX) {
    printf("%.6lf", 360.0 - (180/M_PI)*acos(1.0*ans2/qd));
  }
  else {
    printf("%.6lf", (180/M_PI)*acos(1.0*ans/qd));
  }
  return 0;
}
