#include <cstdio>
:qa
using namespace std;
int main() {
  int i;
  int n;
  int z[200000];
  int chk[200001];
  z[0] = 0;
  int min0 = 300000, max0 = -300000;
  scanf("%d", &n);
  chk[n] = false;
  bool allpos = true;
  for(i=1; i<=n-1; ++i) {
    chk[i] = false;
    int a;
    scanf("%d", &a);
    z[i] = z[i-1]+a;
    if(min0 > z[i]) min0 = z[i];
    if(max0 < z[i]) max0 = z[i];
    if(z[i] < 0) allpos = false;
    if(z[i] > n-1 || z[i] < -n+1 || z[i] == 0) {
      printf("-1");
      return 0;
    }
  }
  int p1;
  if(max0 - min0 == n-2) {
    p1 = allpos ? 1 : n;
  }
  else if(max0 - min0 == n-1) { p1 = -min0 + 1; }
  else {
    printf("-1");
    return 0;
  }
  chk[p1] = true;
  for(i=1; i<=n-1; ++i) {
    int a = z[i] + p1;
    if(a > n || chk[a]) {
      printf("-1");
      return 0;
    }
    chk[a] = true;
  }
  printf("%d ", p1);
  for(i=1; i<=n-1; ++i) printf("%d ", z[i] + p1);
  return 0;
}
