#include <cstdio>
using namespace std;
int TC, tc;
int N, K;
int hmap[8][8];
bool vis[8][8];
int ex[] = {1, 0, -1, 0}, ey[] = {0, 1, 0, -1};
int nop;
int ans;
bool chk(int x, int y) {
  return x>=0 && y>=0 && x<N && y<N && !vis[x][y];
}
void go(int x, int y, int len, bool fl) {
  vis[x][y] = true;
  int h = hmap[x][y];
  int r;
  bool leaf = true;
  for(int i=0; i<4; ++i) {
    int a=x+ex[i], b=y+ey[i];
    if(!chk(a, b)) continue;
    r = 0;
    if(h > hmap[a][b]) {
      leaf = false;
      go(a, b, len+1, fl);
    }
    else if(!fl && h > hmap[a][b] - K) {
      leaf = false;
      int x = hmap[a][b];
      hmap[a][b] = h-1;
      go(a, b, len+1, true);
      hmap[a][b] = x;
    }
  }
  if(leaf && ans < len) ans = len;
  vis[x][y] = false;
}
int main() {
  scanf("%d", &TC);
  for(tc=1; tc<=TC; ++tc) {
    nop = 0;
    ans = 0;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        int a;
        scanf("%d", &a); 
        hmap[i][j] = a;
        vis[i][j] = false;

        if(nop < a) nop = a;
      }
    }
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        if(hmap[i][j] == nop) go(i, j, 1, false);
      }
    }
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
