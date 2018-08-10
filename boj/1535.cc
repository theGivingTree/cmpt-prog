#include <stdio.h>
int N, a[20], ecc[2][100];
int main() {
  int i, j, ans;
  scanf("%d", &N);
  for(i=0; i<N; ++i) scanf("%d", a+i);
  for(i=0; i<N; ++i) {
    int v;scanf("%d", &v);
    int *pre = ecc[i&1], *ec = ecc[~i&1];
    for(j=0; j<100; ++j) ec[j]=pre[j];
    for(j=a[i]; j<100; ++j) {
      if(ec[j] < pre[j-a[i]] + v) ec[j] = pre[j-a[i]] + v;
    }
  }
  int *ec = ecc[N&1];
  printf("%d", ec[99]);
}
