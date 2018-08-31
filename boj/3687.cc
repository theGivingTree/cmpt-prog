#include <cstdio>
#include <climits>
using namespace std;
using ULL = unsigned long long;
ULL const MXX = ULLONG_MAX;
int c[8] = {0,0,1,7,4,2,0,8};
ULL d[101];
int main() {
  int i, j;
  for(i=1; i<=100; ++i) d[i]=MXX/11;
  for(i=2; i<=7; ++i) d[i]=c[i];
  d[6]=6;
  for(i=8; i<=100; ++i) {
    ULL aa=MXX, val;
    for(j=2; j<=7; ++j) {
      val = d[i-j]*10 + c[j];
      if(aa > val) aa = val;
    }
    d[i] = aa;
  }
  int z;
  scanf("%d", &z);
  while(z--) {
    int a;
    scanf("%d", &a);
    printf("%lld ", d[a]);
    if(a&1) {
      putchar('7');
      a-=3;
    }
    for(i=0; i<a/2; ++i) {
      putchar('1');
    }
    puts("");
  }
}
