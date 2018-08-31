#include <cstdio>
using namespace std;
int n, q;
int main() {
  int i, j;
  scanf("%d%d", &n,&q);
  for(i=0; i<q; ++i) {
    int x,y;
    long long ans = 0;
    scanf("%d%d", &x,&y);
    if((x+y)%2 == 1) ans = (1LL*n*n+1)/2;
    ans += (1LL*n*(x-1)+y+1)/2;
    printf("%lld\n", ans);
  }
  return 0;
}
