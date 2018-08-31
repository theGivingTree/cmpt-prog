#include <cstdio>
#include <algorithm>
using namespace std;
int N, L;
int a[1000];
int main() {
  int i, j;
  scanf("%d%d", &N,&L);
  --L;
  for(i=0; i<N; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+N);
  int ans=0;
  i=0;
  while(i<N) {
    j=i;
    while(j<N && a[j]-a[i]<=L) ++j;
    ++ans;
    i=j;
  }
  printf("%d", ans);
  return 0;
}
