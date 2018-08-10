#include <cstdio>
using namespace std;
int TC;
long long inner(int x0, int y0, int x1, int y1) {
  return 1LL*x0*x1 + 1LL*y0*y1;
}
long long inner(int xx[], int yy[], int p, int i, int j) {
  return inner(xx[i]-xx[p], yy[i]-yy[p], xx[j]-xx[p], yy[j]-yy[p]);
}
bool chklen(int xx[], int yy[], int p, int i, int j) {
  long long dxi, dyi, dxj, dyj;
  dxi = xx[i]-xx[p];dyi = yy[i]-yy[p];
  dxj = xx[j]-xx[p];dyj = yy[j]-yy[p];
  return dxi*dxi+dyi*dyi == dxj*dxj+dyj*dyj;
}
bool chkfinal(int xx[], int yy[], int p, int i, int j) {
  int cx = xx[i]+xx[j]-xx[p];
  int cy = yy[i]+yy[j]-yy[p];
  return cx == xx[3] && cy == yy[3];
}
int xx[4], yy[4];
bool go(int p, int i, int j) {
  if(inner(xx, yy, p, i, j) == 0) {
    if(!chklen(xx, yy, p, i, j)) {
      puts("0"); return true;
    }
    if(chkfinal(xx, yy, p, i, j)) {
      puts("1"); return true;
    }
    else {
      puts("0"); return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &TC);
  while(TC--) {
    for(int i=0; i<4; ++i) {
      scanf("%d %d", xx+i, yy+i);
    }
    if(!go(0, 1, 2) && !go(1, 0, 2) && !go(2, 0, 1)) {
      puts("0");
    }
  }
}
