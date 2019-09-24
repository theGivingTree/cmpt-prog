#include <cstdio>
#include <algorithm>
using namespace std;
int L, N, rf, rb;
struct St {
  int x, c;
  bool operator<(St const& rhs) const {
    return c>rhs.c || (c==rhs.c && x<rhs.x);
  }
} rpoints[100000];
int main() {
  int i;
  scanf("%d%d%d%d",&L,&N,&rf,&rb);
  for(i=0; i<N; ++i) {
    scanf("%d%d", &rpoints[i].x, &rpoints[i].c);
  }
  sort(rpoints, rpoints + N);
  
  int anchor = 0;
  long long ans = 0;
  for(i=0; i<N; ++i) {
    if(anchor > rpoints[i].x) continue;
    ans += 1LL * rpoints[i].c * (rpoints[i].x - anchor) * (rf - rb);

    anchor = rpoints[i].x;
  }

  printf("%lld", ans);
  return 0;
}
