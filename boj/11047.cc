#include <cstdio>
using namespace std;
int N, K, a[10], ans;
int main() {
  int i, j;
  scanf("%d %d", &N, &K);
  for(i=0; i<N; ++i) {
    scanf("%d", a+i);
  }
  for(i=N-1; i>=0; --i) {
    ans += K/a[i];
    K%=a[i];
  }
  printf("%d", ans);
}
