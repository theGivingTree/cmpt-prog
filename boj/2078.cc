#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
LL A, B, t, x, y;
bool c;
int main() {
  scanf("%lld %lld", &A, &B);
  while(A>1 && B>1) {
    x+=A/B,t=A,A=B,B=t%B;
    swap(x, y);
    c=!c;
  }
  if(A<B) y+=B-A;
  else x+=A-B;
  if(c) swap(x,y);
  printf("%lld %lld", x, y);
  return 0;
}
