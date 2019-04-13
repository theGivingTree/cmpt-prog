#include <cstdio>
using namespace std;
int N, K, L;
char pam[100][100];
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
bool bchk(int x, int y) {
  return x>=0 && y>=0 && x<N && y<N;
}
int main() {
  scanf("%d %d", &N, &K);
  for(int i=0; i<K; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    pam[a-1][b-1] = '@';
  }
  int hx=0, hy=0, dir=1;
  int tx=0, ty=0;
  pam[hx][hy] = 4+1;
  int t = 1;
  scanf("%d", &L);
  for(int l=0; ; ++l) {
    char _;
    int X, C;
    if(l<L) {
      scanf("%d %c", &X, &_);
      C = _ == 'L' ? 1 : 3;
    }
    else {
      X = 0x7fFFffFF;
      C = 0;
    }
    while(t <= X) {
      int nx = hx + dx[dir], ny = hy + dy[dir];
      if(!bchk(nx, ny)) {
        printf("%d", t);
        return 0;
      }
      char prev = pam[nx][ny];
      pam[nx][ny] = pam[hx][hy];
      hx = nx, hy = ny;
      if(prev != '@') {
        if(prev != 0) {
          // check before erase
          printf("%d", t);
          return 0;
        }
        int td = pam[tx][ty] - 4;
        pam[tx][ty] = 0;
        tx += dx[td], ty += dy[td];
      }
      ++t;
    }
    dir = (dir+C)%4;
    pam[hx][hy] = 4+dir;
  }
  return 0;
}

