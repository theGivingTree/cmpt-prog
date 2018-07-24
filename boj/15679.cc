#include <cstdio>
using namespace std;
using LL = long long;
LL N, C;
int X, Y, Z;
bool solve() {
  if(C==0) {
    X=Y=0, Z=0x7fffffff;
    return true;
  }
  if(N>60) {
    if(C==1) {
      X=Y=Z=0;
      return true;
    }
    else return false;
  }
  // N<=60, C>=1
  LL T1=(1<<(N-1))-1, T2=(1<<(N-1))-2, T3=1<<(N-1);
  int c1=0, c2=0, c3=0;
  if(N%2) {
    if(T1>1) while(C>1 && C%T1==0) C/=T1, ++c1;
    if(C>1) return false;
    X=(1<<c1)-1;
    Y=Z=0;
    return true;
  }
  else {
    if(T2>1) while(C>1 && C%T2==0) C/=T2, ++c2;
    if(T3>1) while(C>1 && C%T3==0) C/=T3, ++c3;
    if(C>1) return false;
    X=(1<<(c2+c3))-1;
    Y=0;
    Z=((1<<c3)-1)<<c2;
    return true;
  }
}
int main() {
  scanf("%lld %lld", &N, &C);
  if(solve()) {
    printf("%d %d %d\n", X, Y, Z);
  }
  else puts("-1");
  return 0;
}
