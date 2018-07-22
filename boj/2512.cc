#include <cstdio>
using namespace std;
int N, a[10000], X, _max;
int main() {
  int i;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    scanf("%d", a+i);
    if(_max < a[i]) _max = a[i];
  }
  scanf("%d", &X);
  
  int lo=0, hi=_max, m;
  while(lo<hi) {
    m=(lo+hi+1)/2;
    int sum=0;
    for(i=0; i<N; ++i) {
      int v = a[i];
      if(v > m) v=m;
      sum+=v;
    }
    if(sum <= X) lo=m;
    else hi=m-1;
  }
  printf("%d", lo);
  return 0;
}
