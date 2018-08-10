#include <stdio.h>
int main() {
  int n, a=1, b=1;
  scanf("%d", &n);
  while(n---1) a=(a+b)%10007, b=(a-b+10007)%10007;
  printf("%d", a);
  return 0;
}
