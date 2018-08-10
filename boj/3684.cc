#include <cstdio>
using namespace std;
int const MOD = 10001;
int const HALF = 5001;
int T, xq[100];
int gcd(int a, int b) {
  int t;while(b) t=b,b=a%b;a=t;
  return a;
}
int xgcd(int a, int b, int& y) {
  int aa=a;
  int t=0, tt=1, q;
  int u;while(b) {
    q=a/b;
    u=b,b=a%b,a=u;
    u=tt,tt=t-q*tt,t=u;
  }
  if(t<0) t+=aa;
  y=t;
  return a;
}
void solve() {
  int i, j;
  if(xq[0] == xq[1]) {
    for(i=0; i<T; ++i) {
      printf("%d\n", xq[0]);
    }
    return;
  }

  int c1=xq[1]-xq[0], c2=xq[2]-xq[1], inv;
  c1+=MOD, c2+=MOD;
  int g = xgcd(MOD, c1, inv), mod = MOD/g;
  int A = c2*inv/g%mod, a, b;
  for(i=0; i<mod; ++i) {
    if(i*i%mod != A) continue;
    a = i;

    c1 = a + 1;
    c2 = (xq[1]+(MOD-A)*xq[0])%MOD;
    g = xgcd(MOD, c1, inv);
    b = c2*inv/g%(MOD/g);

    int x = xq[0];
    for(j=0; j<T; ++j) {
      if(x != xq[j]) break;
      x=(a*x+b)%MOD;
      x=(a*x+b)%MOD;
    }
    if(j==T) break;
  }

  for(i=0; i<T; ++i) {
    printf("%d\n", (a*xq[i]+b)%MOD);
  }
}
int main() {
  scanf("%d", &T);
  for(int i=0; i<T; ++i) scanf("%d", xq+i);
  if(T==1) puts("0");
  else if(T==2) {
    int b = (xq[1]-xq[0]+MOD)*HALF%MOD;
    printf("%d\n%d\n", (xq[0]+b)%MOD, (xq[1]+b)%MOD);
  }
  else solve();
  return 0;
}
