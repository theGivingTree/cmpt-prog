#include <cstdio>
#include <algorithm>
using namespace std;
struct Crd {
  int x, y;
  bool operator<(Crd const &rhs) const { return x<rhs.x || x==rhs.x && y>rhs.y; }
} arr[100000];
int upd[100000];
int main() {
  int i;
  int N;
  scanf("%d",&N);
  for(i=0; i<N; ++i) {
    int x, y;
    scanf("%d%d", &x,&y);
    arr[i].x = x;
    arr[i].y = y;
    upd[i] = 0x7fFFffFF;
  }
  sort(arr, arr+N);
  int lastx = -1, M = 0, X = 0;
  for(i=0; i<N; ++i) {
    if(lastx != arr[i].x) {
      lastx = arr[i].x;
      int Xx = arr[i].x + arr[i].y;
      if(X >= Xx) continue;
      X = Xx;
      M = lower_bound(upd, upd+M, arr[i].x-arr[i].y) - upd;
      upd[M] = arr[i].x-arr[i].y;
      ++M;
    }
  }
  printf("%d", M);
  return 0;
}
