#include <cstdio>
using namespace std;
int n, m;
bool cc[101];
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    for(j=l; j<=r; ++j) cc[j] = true;
  }
  int cnt = 0;
  for(i=1; i<=m; ++i) {
    if(!cc[i]) ++cnt;
  }
  printf("%d\n", cnt);
  for(i=1; i<=m; ++i) {
    if(!cc[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}
