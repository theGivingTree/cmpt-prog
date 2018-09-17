#include <cstdio>
using namespace std;
int n, m, cc[101];
int main() {
  int i, j, ans;
  scanf("%d %d", &n, &m);
  for(i=0; i<m; ++i) {
    int v;
    scanf("%d", &v);
    ++cc[v];
  }
  for(ans=1; ans<=m; ++ans) {
    int sum=0;
    for(i=1; i<=100; ++i) {
      sum += cc[i]/ans;
    }
    if(sum < n) break;
  }
  printf("%d", ans-1);
  return 0;
}
