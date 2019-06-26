#include <cstdio>
#include <algorithm>
using namespace std;
int each() {
  int i;
  int n, k, a[100];
  scanf("%d %d", &n, &k);
  for(i=0; i<n; ++i) scanf("%d", &a[i]);
  sort(a, a+n);
  if(a[n-1] - a[0] > 2*k) return -1;
  return a[0] + k;
}
int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    printf("%d\n", each());
  }
  return 0;
}
