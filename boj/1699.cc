#include <stdio.h>
#define R_MAX 316
int legendre(int N) {
  while((N&3)==0) N>>=2;
  return (N+1)%8;
}
int main() {
  int i, j;
  int N;
  scanf("%d", &N);
  for(i=1; i<=R_MAX; ++i) if(i*i==N) {puts("1");return 0;}
  for(i=1; i<=R_MAX; ++i) for(j=i; j<=R_MAX; ++j) if(i*i+j*j==N) {puts("2");return 0;}
  if(legendre(N)) {puts("3");return 0;}
  puts("4");
  return 0;
}
