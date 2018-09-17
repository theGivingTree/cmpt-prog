#include <cstdio>
using namespace std;
int n;
int pa[1001];
bool visit[1001];
bool cycle[1001];
int ans[1001];
int chk(int x) {
  if(visit[x]) return x;
  visit[x] = true;
  return chk(pa[x]);
}
void mark(int x, int r) {
  cycle[x] = true;
  ans[x] = x;
  if(r == pa[x]) return;
  mark(pa[x], r);
}
int go(int x) {
  if(cycle[x]) return x;
  return go(pa[x]);
}

int shit(int x) {
  if(visit[x]) return x;
  visit[x] = true;
  return shit(pa[x]);
}
int main() {
  int i, j;
  scanf("%d", &n);
  for(i=1; i<=n; ++i) {
    int p;
    scanf("%d", &p);
    pa[i] = p;
  }
  for(i=1; i<=n; ++i) {
    for(j=1; j<=n; ++j) visit[j] = false;
    printf("%d\n", shit(i));
  }
  return 0;
}
