#include <cstdio>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(m%n != 0) {
    printf("-1");
    return 0;
  }
  int q = m/n;
  int ans = 0;
  while(q%2 == 0) q/=2, ++ans;
  while(q%3 == 0) q/=3, ++ans;
  if(q != 1) {
    printf("-1");
  }
  else {
    printf("%d", ans);
  }
  return 0;
}
