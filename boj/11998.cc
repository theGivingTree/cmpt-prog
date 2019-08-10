#include <cstdio>
#include <cstdlib>
using namespace std;
int X, Y, K ,M;
int d[101][101];
int ans = 0x7fFFffFF;
int mmin(int x, int y) {
  return x<y?x:y;
}
void upt(int x, int y, int v) {
  int &r = d[x][y];
  if(r == 0 || r > v) {
    int z = abs(M-(x+y));
    if(ans > z) ans = z;
    r = v;
  }
}
int main() {
  int i;
  scanf("%d%d%d%d",&X,&Y,&K,&M);
  d[0][0] = 1;
  for(i=1; i<=K; ++i) {
    int x, y;
    for(x=0; x<=X; ++x) {
      for(y=0; y<=Y; ++y) {
        int c = d[x][y];
        if(c != i) continue;
        upt(X, y, c+1);
        upt(x, Y, c+1);
        upt(0, y, c+1);
        upt(x, 0, c+1);

        int a;
        a = mmin(X-x, y);
        upt(x+a, y-a, c+1);
        a = mmin(Y-y, x);
        upt(x-a, y+a, c+1);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
