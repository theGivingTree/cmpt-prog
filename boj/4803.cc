#include <cstdio>
using namespace std;
int tc;
int n, m, ans;
bool aa[500][500];
bool as[500];
bool go(int x, int p) {
  as[x] = true;
  for(int i=0; i<n; ++i) if(i!=p && aa[x][i] && (as[i] || !go(i, x))) return false;
  return true;
}
int main() {
  while(scanf("%d %d", &n, &m), n) {
    ++tc;
    for(int i=0; i<n; ++i)  {
      as[i] = false;
      for(int j=0; j<n; ++j) aa[i][j] = false;
    }
    for(int i=0; i<m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y), --x, --y;
      aa[x][y] = true;
      aa[y][x] = true;
    }
    ans = 0;
    for(int i=0; i<n; ++i) {
      if(!as[i]) {
        ans += go(i, -1);
      }
    }
    printf("Case %d: ", tc);
    if(ans > 1) printf("A forest of %d trees.\n", ans);
    else puts(ans == 1 ? "There is one tree." : "No trees.");
  }
  return 0;
}
