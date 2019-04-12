#include <cstdio>
#include <algorithm>
using namespace std;
int TC;
int N, ans;
bool dead[1000];
int x[1000], y[1000], d[1000], K[1000];
int xL, xR, yL, yR;
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
int ddremap[]={1, 3, 2, 0};
bool bchk(int x, int y) {
  return x>=xL && x<=xR && y>=yL && y<=yR;
}
int main() {
  scanf("%d", &TC);
  for(int tc=1; tc<=TC; ++tc) {
    ans = 0;
    scanf("%d", &N);
    xL=9999, xR=0, yL=9999, yR=0;
    for(int i=0; i<N; ++i) {
      dead[i] = false;
      scanf("%d %d %d %d", &x[i], &y[i], &d[i], &K[i]);
      d[i] = ddremap[d[i]];
      if(xL > x[i]) xL = x[i];
      if(xR < x[i]) xR = x[i];
      if(yL > y[i]) yL = y[i];
      if(yR < y[i]) yR = y[i];
    }
    int Tl = xR-xL > yR-yL ? xR-xL : yR-yL;
    for(int tl=0; tl<Tl; ++tl) {
      int coables[1000], n_c = 0;
      for(int i=0; i<N; ++i) {
        if(dead[i]) continue;
        int xc=x[i], yc=y[i], dc=d[i];
        int nx=xc+dx[dc], ny=yc+dy[dc];
        if(!bchk(nx, ny)) {
          dead[i] = true;
          continue;
        }
        x[i]=nx, y[i]=ny;
        coables[n_c++] = i;
      }
      sort(coables, coables+n_c, [](int a, int b) {
        return x[a] < x[b] || (x[a] == x[b] && y[a] < y[b]);
      });
      int i=0;
      while(i<n_c) {
        int ti = coables[i];
        int nx=x[ti], ny=y[ti];
        int sum = K[ti];
        int old_i = i++;
        while(i<n_c && (nx == x[coables[i]] && ny == y[coables[i]])) {
          sum += K[coables[i]];
          ++i;
        }
        if(i - old_i > 1) {
          ans += sum;
          for(int j=old_i; j<i; ++j) {
            dead[coables[j]] = true;
          }
        }
      }
    }
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
