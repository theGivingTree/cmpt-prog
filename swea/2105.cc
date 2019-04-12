#include <cstdio>
using namespace std;
int TC;
int N;
int dmap[20][20];
int dx[]={1, 1, -1, -1}, dy[]={1, -1, -1, 1};
bool chk_bound(int x, int y) {
  return x>=0 && y>=0 && x<N && y<N;
}
int main() {
  scanf("%d", &TC);
  for(int tc=1; tc<=TC; ++tc) {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        scanf("%d", &dmap[i][j]);
        --dmap[i][j];
      }
    }
    int ans = -1;
    for(int i=0; i<N-2; ++i) {
      for(int j=1; j<N-1; ++j) {
        int s1_up = N-1-(j > i ? j : i);
        for(int s1=1; s1<=s1_up; ++s1) {
          int s2_up = N-1-i-s1 < j ? N-1-i-s1 : j;
          for(int s2=1; s2<=s2_up; ++s2) {
            bool vis[100] = {};
            int SS[] = {s1, s2, s1, s2};
            int ii=i, jj=j;
            for(int d=0; d<4; ++d) {
              int s=0;
              while(s<SS[d]) {
                if(vis[dmap[ii][jj]]) {
                  goto re;
                }
                vis[dmap[ii][jj]] = true;
                ii+=dx[d], jj+=dy[d];
                ++s;
              }
            }
            if(ans < 2*(s1 + s2)) ans = 2*(s1 + s2);
re:;
          }
        }
      }
    }
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
