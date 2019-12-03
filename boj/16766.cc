#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, C;
int ta[100000];
int main() {
  int i;
  scanf("%d%d%d",&N,&M,&C);
  for(i=0; i<N; ++i) {
    scanf("%d",&ta[i]);
  }
  sort(ta, ta+N);
  int lo, hi;
  lo = 0;
  hi = ta[N-1] - ta[0];
  while(lo<hi) {
    int mi = (lo+hi)/2;

    int cowIdx = 0, busIdx = 0;
    int fcow = 0, n = 0;
    while(cowIdx<N && busIdx<M) {
      if(ta[cowIdx] - ta[fcow] <= mi && n < C) {
        ++cowIdx;
        ++n;
      }
      else {
        ++busIdx;
        fcow = cowIdx;
        n = 0;
      }
    }

    if(cowIdx<N) lo = mi+1;
    else hi = mi;
  }

  printf("%d", hi);
  return  0;
}
