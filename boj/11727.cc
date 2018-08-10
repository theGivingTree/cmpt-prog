#include <stdio.h>
int main() {
  int n, a=1, b=1;
  scanf("%d", &n);
  while(n---1) a=(a+2*b)%10007, b=(a-2*b+20014)%10007;
  printf("%d", a);
  return 0;
}
