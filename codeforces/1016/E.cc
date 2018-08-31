#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
int sy, a, b, n;
int L[200000], R[200000];
int psum[200001];

int findleft(int x, int y) {
  int ret = -1;
  int lo=0, hi=n-1, mi;
  LL ydel = y-sy, xy = 1LL*x*y;
  while(lo<=hi) {
    mi = (lo+hi)/2;

    LL mR;
    mR = ydel*(R[mi]-x) + xy;
    if(1LL*y*a < mR) {
      hi = mi-1;
      ret = mi;
    }
    else lo = mi+1;
  }
  return ret;
}

int findright(int x, int y) {
  int ret = -1;
  int lo=0, hi=n-1, mi;
  LL ydel = y-sy, xy = 1LL*x*y;
  while(lo<=hi) {
    mi = (lo+hi)/2;

    LL mL;
    mL = ydel*(L[mi]-x) + xy;
    if(mL < 1LL*y*b) {
      lo = mi+1;
      ret = mi;
    }
    else hi = mi-1;
  }
  return ret;
}

int main() {
  int i, j;
  scanf("%d %d %d %d", &sy, &a, &b, &n);
  for(i=0; i<n; ++i) {
    scanf("%d %d", &L[i], &R[i]);
  }
  for(i=1; i<=n; ++i) {
    psum[i] = psum[i-1] + R[i-1] - L[i-1];
  }

  int q;
  scanf("%d", &q);
  while(q--) {
    int x, y, ii, jj;
    scanf("%d %d", &x, &y);

    LL ans = 0, iiL, jjR;
    LL ydel = y-sy, xy = 1LL*x*y;
    LL A = 1LL*y*a, B = 1LL*y*b;

    ii = findleft(x, y);
    if(ii == -1) {
      puts("0");
      continue;
    }
    jj = findright(x, y);
    if(jj == -1) {
      puts("0");
      continue;
    }

    iiL = ydel*(L[ii]-x) + xy;
    if(A < iiL) iiL = A;
    jjR = ydel*(R[jj]-x) + xy;
    if(jjR < B) jjR = B;
    ans = ydel*(psum[jj+1] - psum[ii]);
    ans -= (A - iiL) + (jjR - B);
    printf("%.6lf\n", 1.0*ans/y);
  }
  return 0;
}
