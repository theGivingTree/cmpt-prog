#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
int T;
int solve(int a[], int n, int b[], int m) {
  int ans;
  int lo, hi, md, lo2, hi2, md2, planb=-1;

  LL X = 1LL*n*m, cntMin=1, cntMax;
  lo=0, hi=n-1;
  lo2=0, hi2=m;
  while(lo<hi) {
    md=(lo+hi+1)/2;

    int lt=lo2, ht=hi2;
    while(lt<ht) {
      md2=(lt+ht)/2;
      if(b[md2]<a[md]) lt=md2+1;
      else ht=md2;
    }
    int idxA = md, idxB = lt-1;
    LL cM = 1LL*(idxB+1)*n + 1LL*idxA*m + 1;

    if(cM>X) {
      hi=md-1;
    }
    else {
      lo=md;
      cntMin = cM;
      planb=idxB;
    }
  }
  ans = a[lo];
  cntMax = (cntMin-1) + m;
  if(X > cntMax) {
    ans = b[planb+(X-cntMax+n-1)/n];
  }
  return ans;
}
int main() {
  int n, m, a[1000001], b[1000001];
  scanf("%d", &T);
  while(T--) {
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; ++i) scanf("%d", a+i);
    for(i=0; i<m; ++i) scanf("%d", b+i);
    sort(a, a+n);
    sort(b, b+m);
    a[n]=b[m]=0x7fffffff;
    printf("%d.0\n", a[0]<=b[0]?solve(a,n,b,m):solve(b,m,a,n));
  }
  return 0;
}
