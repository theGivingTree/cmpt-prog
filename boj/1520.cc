#include <cstdio>
using namespace std;
int M, N;
int jido[500][500], cc[500][500];
int ddx[]={1, 0, -1, 0}, ddy[]={0, 1, 0 ,-1};
bool bchk(int x, int y) {
  return x>=0 && x<M && y>=0 && y<N;
}
int go(int cx, int cy) {
  int s = 0;
  for(int i=0; i<4; ++i) {
    int nx = cx + ddx[i], ny = cy + ddy[i];
    if(!bchk(nx, ny) || jido[cx][cy] <= jido[nx][ny] || cc[nx][ny] == 0) continue;
    if(cc[nx][ny] == -1) go(nx, ny);
    s += cc[nx][ny];
  }
  return cc[cx][cy] = s;
}
int main() {
  scanf("%d %d", &M, &N);
  for(int i=0; i<M; ++i) {
    for(int j=0; j<N; ++j) {
      scanf("%d", &jido[i][j]);
      cc[i][j] = -1;
    }
  }
  cc[M-1][N-1] = 1;
  printf("%d", go(0, 0));
  return 0;
}
