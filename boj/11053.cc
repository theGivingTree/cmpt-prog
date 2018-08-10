#include <stdio.h>
int N, A[1000];
int main() {
  int i, j, a, lo, hi, H=0;
  scanf("%d", &N);
  hi=0;
  for(i=0; i<N; ++i) {
    scanf("%d", &a);
    lo=0;hi=H;
    while(lo<hi) {
      j=(lo+hi)/2;
      if(a>A[j]) lo=j+1;
      else hi=j;
    }
    A[hi]=a;
    if(hi==H) ++H;
  }
  printf("%d", H);
  return 0;
}
