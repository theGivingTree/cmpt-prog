#include <cstdio>
#include <algorithm>
using namespace std;
int const XMIN = -1'000'000'000, XMAX = 1'000'000'000;
struct AA {
  int s, e;
  bool operator<(AA rhs) const {
    return s < rhs.s;
  }
} aal[1000001];
int N;
int main() {
  int i, j;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    scanf("%d%d", &aal[i].s, &aal[i].e);
  }
  sort(aal, aal+N);
  aal[N].s = aal[N].e = XMAX+1;
  int ans = 0;
  int ss = XMIN, ee = XMIN;
  for(i=0; i<=N; ++i) {
    int s, e;
    s = aal[i].s;
    e = aal[i].e;
    if(ee < s) {
      ans += ee-ss;
      ss = s;
      ee = e;
    }
    else if(ee < e) ee = e; 
  }
  printf("%d", ans);
}
