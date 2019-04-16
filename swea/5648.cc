#include <cstdio>
#include <algorithm>
using namespace std;
int TC;
int N, ans;
int grid[2001][2001];
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
    for(int i=0; i<=2000; ++i) {
      for(int j=0; j<=2000; ++j) {
        grid[i][j] = -1;
      }
    }
    xL=9999, xR=0, yL=9999, yR=0;
    for(int i=0; i<N; ++i) {
      scanf("%d %d %d %d", &x[i], &y[i], &d[i], &K[i]);
      x[i] += 1000;
      y[i] += 1000;
      grid[x[i]][y[i]] = i;
      d[i] = ddremap[d[i]];
      if(xL > x[i]) xL = x[i];
      if(xR < x[i]) xR = x[i];
      if(yL > y[i]) yL = y[i];
      if(yR < y[i]) yR = y[i];
    }

    int remain = N;
    for(int tl=1; remain; ++tl) {
      for(int i=0; i<N; ++i) {
        int xi=x[i], yi=y[i], di=d[i], Ki=K[i];
        if(grid[xi][yi] == -1) continue;
        if(tl&1) {
          int t, xt, yt;
          xt = xi+tl*dx[di], yt = yi+tl*dy[di];
          if(!bchk(xt, yt) || (t=grid[xt][yt]) == -1 || (d[t]+2)%4 != di) continue;
          ans += Ki + K[t];
          grid[xi][yi] = grid[xt][yt] = -1;
          remain -= 2;
        }
        else {
          int ll = tl/2;
          int xm = xi + ll*dx[di], ym = yi + ll*dy[di];
          if(!bchk(xm, ym)) {
            grid[xi][yi] = -1;
            --remain;
            continue;
          }

          int cnt = 0;
          for(int s=0; s<4; ++s) {
            int t, xt, yt;
            xt = xm + ll*dx[s], yt = ym + ll*dy[s];
            if(!bchk(xt, yt) || (t=grid[xt][yt]) == -1 || (d[t]+2)%4 != s) continue;
            ++cnt;
          }
          if(cnt == 1) continue;

          int sum = 0;
          for(int s=0; s<4; ++s) {
            int t, xt, yt;
            xt = xm + ll*dx[s], yt = ym + ll*dy[s];
            if(!bchk(xt, yt) || (t=grid[xt][yt]) == -1 || (d[t]+2)%4 != s) continue;
            sum += K[t];
            grid[xt][yt] = -1;
          }
          ans += sum;
          remain -= cnt;
        }
      }
    }

    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
