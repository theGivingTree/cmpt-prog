#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;
int google[301];
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for(i=1; i<=N; ++i) {
    scanf("%d", google+i);
    google[i]+=google[i-1];
  }
  int lo=0, hi=google[N], m;
  while(lo<hi) {
    m=(lo+hi)/2;
    int k=1, acc=0;
    for(j=0; j<M; ++j) {
      k = lower_bound(google+k, google+N+1, acc+m) - google;
      if(k>N) break;
      if(google[k]>acc+m) --k;
      acc = google[k++];
    }
    if(k>N) hi = m;
    else lo = m+1;
  }
  printf("%d\n", lo);
  int lk=0, k=1, acc=0;
  for(j=0; j<M-1; ++j) {
    k = lower_bound(google+k, google+N+1, acc+lo) - google;
    if(google[k]>acc+lo) --k;
    int bound = N-(M-(j+1));
    if(k>bound) k=bound;
    printf("%d ", k-lk);
    lk=k;
    acc = google[k++];
  }
  printf("%d ", N-lk);
  return 0;
}
