#include <cstdio>
#include <algorithm>
using namespace std;
int N;
char icboard[12][12];
struct {
  int x, y;
} core_pos_list[12];
bool active[12];
int n_cores;
struct {
  int x1, y1, x2, y2, ci;
} cblrg[48];
int n_cblrg;
int aa, aax;
int bb, bbx;
void go(int cur) {
  if(cur == n_cblrg) {
    if(aax < aa) {
      aax = aa;
      bbx = bb;
    }
    else if(aax == aa && bbx > bb) {
      bbx = bb;
    }
    return;
  }

  int x1, y1, x2, y2;
  int core_id = cblrg[cur].ci;
  go(cur+1);
  if(active[core_id]) return;
  x1 = cblrg[cur].x1;
  y1 = cblrg[cur].y1;
  x2 = cblrg[cur].x2;
  y2 = cblrg[cur].y2;
  if(x1 == x2) {
    for(int j=y1; j<=y2; ++j) {
      if(icboard[x1][j] >= 1) return;
    }
    for(int j=y1; j<=y2; ++j) {
      icboard[x1][j] += 2;
    }
    active[core_id] = true;
    ++aa;
    bb += y2-y1+1;
    go(cur+1);
    bb -= y2-y1+1;
    --aa;
    active[core_id] = false;
    for(int j=y1; j<=y2; ++j) {
      icboard[x1][j] -= 2;
    }
  }
  else {
    for(int i=x1; i<=x2; ++i) {
      if(icboard[i][y1] >= 1) return;
    }
    for(int i=x1; i<=x2; ++i) {
      icboard[i][y1] += 2;
    }
    active[core_id] = true;
    ++aa;
    bb += x2-x1+1;
    go(cur+1);
    bb -= x2-x1+1;
    --aa;
    active[core_id] = false;
    for(int i=x1; i<=x2; ++i) {
      icboard[i][y1] -= 2;
    }
  }
}
int main() {
  int Tc;
  scanf("%d", &Tc);
  for(int tc=1; tc<=Tc; ++tc) {
    n_cores = 0;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        int a;
        scanf("%d", &a);
        icboard[i][j] = a;
        if(a == 1) {
          core_pos_list[n_cores++] = {i, j};
        }
      }
    }
    n_cblrg = 0;
    for(int i=0; i<n_cores; ++i) {
      active[i] = false;
      auto p = &core_pos_list[i];
      if(p->x == 0 || p->y == 0 || p->x == N-1 || p->y == N-1) continue;
      int dx[] = {1, 0, -1, 0};
      int dy[] = {0, 1, 0, -1};
      for(int d=0; d<4; ++d) {
        int s = 1;
        while(true) {
          int x, y;
          x = p->x + s*dx[d];
          y = p->y + s*dy[d];
          if(x<0 || y<0 || x>=N || y>=N) {
            int x1, y1, x2, y2;
            x1 = p->x + dx[d];
            y1 = p->y + dy[d];
            x2 = p->x + (s-1)*dx[d];
            y2 = p->y + (s-1)*dy[d];
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            cblrg[n_cblrg++] = {x1, y1, x2, y2, i};
            break;
          }
          else if(icboard[x][y]) break;
          ++s;
        }
      }
    }
    aa = 0, aax = 0;
    bb = 0, bbx = 0x7fFFffFF;
    go(0);
    printf("#%d %d\n", tc, bbx);
  }
  return 0;
}
