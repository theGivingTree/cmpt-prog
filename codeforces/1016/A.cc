#include <cstdio>
using namespace std;
int n, m;
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  long long r=0, s=0;
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    r+=a;
    printf("%lld ", r/m - s);
    s = r/m;
  }
}
