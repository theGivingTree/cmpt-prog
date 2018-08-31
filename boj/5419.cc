#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
struct SM {
  int x, y, yi;
} sms[75000];
int cc[75001];
int xft[75001];
void update(int i, int v) {
  for(; i<=N; i+=i&-i) xft[i]+=v;
}
int query(int i) {
  int s=0;
  for(; i>0; i-=i&-i) s+=xft[i];
  return s;
}
void solve() {
  int i;
  scanf("%d", &N);
  memset(cc+1, 0, N*sizeof(int));
  memset(xft+1, 0, N*sizeof(int));
  for(i=0; i<N; ++i) scanf("%d%d", &sms[i].x, &sms[i].y);
  sort(sms, sms+N, [](SM lhs, SM rhs) {
    return lhs.y < rhs.y;
  });
  int lasty=-1'000'000'001, lasti=0;
  for(i=0; i<N; ++i) {
    if(lasty != sms[i].y) {
      cc[i+1]=0;
      sms[i].yi = i+1;
      lasti = i+1;
      lasty = sms[i].y;
    }
    else {
      ++cc[lasti];
      sms[i].yi = lasti;
    }
  }

  sort(sms, sms+N, [](SM lhs, SM rhs) {
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y > rhs.y);
  });

  long long ans = 0;
  for(i=0; i<N; ++i) {
    int yi = sms[i].yi;
    ans += (yi + cc[yi] - 1) - query(yi);
    update(yi, 1);
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) solve();
  return 0;
}
