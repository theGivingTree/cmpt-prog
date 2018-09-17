#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, a[300000];
int main() {
  long long sum = 0;
  int i;
  scanf("%d%d", &n, &k);
  for(i=0; i<n; ++i) scanf("%d", a+i);
  sort(a, a+n);
  for(i=0; i<n; ++i) {
    int g = i;
    if(g>k) g=k;
    sum += 1LL*g*a[i];
  }
  printf("%lld", sum);
  return 0;
}
