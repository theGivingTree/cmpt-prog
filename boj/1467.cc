#include <cstdio>
#include <algorithm>
using namespace std;
int mul_inv(int m, int b) {
  int a=m, t0=0, t1=1, q;
  while(b) {
    q = a/b;
    a=a%b; swap(a, b);
    t0=t0-t1*q; swap(t0, t1);
  }
  if(t0<0) t0+=m;
  return t0;
}
int crt(int a1, int m1, int a2, int m2) {
  return (a1*m2*mul_inv(m1, m2) + a2*m1*mul_inv(m2, m1)) % (m1*m2);
}
int main() {
  int e, s, m;
  scanf("%d %d %d", &e, &s, &m), --e, --s, --m;
  printf("%d", crt(crt(e, 15, s, 28), 15*28, m, 19)+1);
  return 0;
}
