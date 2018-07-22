#include <cstdio>
int N, M, sum, _max;
int aa[100000];
int main() {
  int i;
  scanf("%d %d", &N, &M);
  for(i=0; i<N; ++i) {
    scanf("%d", aa+i);
    if(_max < aa[i]) _max = aa[i];
    sum += aa[i];
  }

  int lo=_max, hi=sum, m;
  while(lo<hi) {
    m=(lo+hi)/2;
    int cnt=1, bal=m;
    for(i=0; i<N && cnt<=M; ++i) {
      if(bal < aa[i]) {
        bal=m;
        ++cnt;
      }
      bal -= aa[i];
    }
    if(cnt > M) lo=m+1;
    else hi=m;
  }
  printf("%d", lo);
  return 0;
}
