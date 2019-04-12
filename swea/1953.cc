#include <cstdio>
using namespace std;
int TC;
int N, M, R, C, L;
int tmap[50][50];
int ta[50][50];
bool hdir[8][4] = {
  {}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 0, 1, 1}
};
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
int ans;
bool movable(int x, int y, int d) {
  if(!hdir[tmap[x][y]][d]) return false;
  x+=dx[d], y+=dy[d];
  return x>=0 && y>=0 && x<N && y<M && hdir[tmap[x][y]][(d+2)%4];
}
void go(int x, int y, int ll) {
  if(ll == L) return;
  for(int d=0; d<4; ++d) {
    if(!movable(x, y, d)) continue;
    int nx=x+dx[d], ny=y+dy[d];
    if(ta[nx][ny] > ta[x][y]+1) {
      ta[nx][ny] = ta[x][y]+1;
      go(nx, ny, ll+1);
    }
  }
}
int main() {
  scanf("%d", &TC);
  for(int tc=1; tc<=TC; ++tc) {
    ans = 0;
    scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
    for(int i=0; i<N; ++i) {
      for(int j=0; j<M; ++j) {
        int a;
        scanf("%d", &a);
        tmap[i][j] = a;
        ta[i][j] = 0x7fFFffFF;
      }
    }
    ta[R][C] = 1;
    go(R, C, 1);
    for(int i=0; i<N; ++i) {
      for(int j=0; j<M; ++j) {
        if(ta[i][j] != 0x7fFFffFF) ++ans;
      }
    }
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
