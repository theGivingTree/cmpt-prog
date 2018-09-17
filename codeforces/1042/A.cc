#include <cstdio>
using namespace std;
int n, m, aa[100];
int main() {
  int i;
  scanf("%d%d", &n, &m);
  int maxa = 0, s=0;
  for(i=0; i<n; ++i) {
    scanf("%d", aa+i);
    if(maxa < aa[i]) maxa = aa[i];
  }
  for(i=0; i<n; ++i) {
    s += maxa - aa[i];
  }
  int m0 = m;
  m -= s;
  if(m < 0) m = 0;
  printf("%d %d", maxa + (m+(n-1))/n, maxa + m0);
  return 0;
}
