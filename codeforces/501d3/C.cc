#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, dd[100000];
long long S;
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    S += a;
    dd[i] = a-b;
  }
  sort(dd, dd+n);
  for(i=n; i>0 && S>m;) S -= dd[--i];
  if(S>m) puts("-1");
  else {
    printf("%d", n-i);
  }
  return 0;
}
