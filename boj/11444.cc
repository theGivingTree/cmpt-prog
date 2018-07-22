#include <stdio.h>
int const M = 15746;
int main() {
  int N, i;
  scanf("%d", &N);++N;
  int a=0, b=1, t;
  for(i=20; i--;) {
    t = a*(2*b-a+M)%M;
    b = (a*a+b*b)%M;
    a = t;
    if(N&1<<i) b+=a, a=b-a;
  }
  printf("%d", a);
  return 0;
}
