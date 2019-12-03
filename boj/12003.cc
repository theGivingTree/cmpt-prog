#include <cstdio>
#include <algorithm>
using namespace std;
int N, K, ar[50000], rr[50000];
int main() {
  int i, ss;
  scanf("%d%d",&N,&K);
  for(i=0; i<N; ++i) {
    scanf("%d", &ar[i]);
  }
  if(N==1) {printf("1");return 0;}
  sort(ar,ar+N);
  ss=i=N-1;
  while(i>=1) {
    while(ar[ss]-ar[i]>K) --ss;
    rr[i] = ss-i+1;
    --i;
  }

  ss = 0;
  i = 1;
  int lx = 1;
  int ans = 0;
  while(i<N) {
    while(ar[i-1]-ar[ss]>K) ++ss;
    if(lx < i-ss) lx = i-ss;
    if(ans<lx+rr[i]) ans = lx+rr[i];
    ++i;
  }
  printf("%d",ans);
  return 0;
}
