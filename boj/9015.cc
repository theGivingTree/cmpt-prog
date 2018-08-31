#include <cstdio>
#include <algorithm>
using namespace std;
int TC;
int N, pp[3001];
int main() {
  scanf("%d", &TC);
  while(TC--) {
    int i, j;
    scanf("%d", &N);
    for(i=0; i<N; ++i) {
      int x, y;
      scanf("%d %d", &x, &y), x+=10000, y+=10000;
      pp[i]=x+20001*y;
    }
    pp[N] = 0x7fFFffFF;
    sort(pp, pp+N);
    int ans = 0;
    for(i=0; i<N; ++i) {
      for(j=i+1; j<N; ++j) {
        int xi, yi, xj, yj, vx, vy, ex, ey;
        xi = pp[i]%20001;
        xj = pp[j]%20001;
        yi = pp[i]/20001;
        yj = pp[j]/20001;
        if(!(xi<xj && yi<=yj)) continue;
        vx = xj-xi, vy = yj-yi;
        if(vx+vy+(1<<20)&1) continue;
        int nx, ny, nnn;
        ex = (vx-vy)/2, ey = (vy+vx)/2;

        nx = xi+ex, ny = yi+ey;
        if(nx<0 || nx>20000 || ny<0 || ny>20000) continue;
        nnn = nx+20001*ny;
        if(*lower_bound(pp, pp+N, nnn) != nnn) continue;

        nx = xi+ey, ny = yi-ex;
        if(nx<0 || nx>20000 || ny<0 || ny>20000) continue;
        nnn = nx+20001*ny;
        if(*lower_bound(pp, pp+N, nnn) != nnn) continue;

        int area = (xi-nx)*(xi-nx) + (yi-ny)*(yi-ny);
        if(ans < area) ans = area;
      }
    }
    printf("%d\n", ans);
  }
}
