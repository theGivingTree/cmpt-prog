#include <stdio.h>
int n, c[5];
int main() {
  int i;
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == 0 || y == 0) ++c[4];
    else {
      if(y<0) x=-x;
      ++c[(x<0)+2*(y<0)];
    }
  }
  for(i=1; i<=4; ++i) printf("Q%d: %d\n", i, c[i-1]);
  printf("AXIS: %d", c[4]);
  return 0;
}
