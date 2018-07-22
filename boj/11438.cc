#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> alist[100001];
int dd[100001];
int papa[100001][17];
void dfs(int u) {
  for(auto v: alist[u]) {
    if(dd[v]) continue;
    papa[v][0] = u;
    dd[v] = dd[u]+1;
    dfs(v);
  }
}
int lca(int x, int y) {
  int i;
  if(dd[x] < dd[y]) swap(x, y);
  int diff;
  for(i=0, diff=dd[x]-dd[y]; diff; ++i, diff>>=1) {
    if((diff&1)==0) continue;
    x = papa[x][i];
  }
  if(x==y) return x;
  for(i=17; i--;) {
    if(papa[x][i] != papa[y][i]) {
      x=papa[x][i];
      y=papa[y][i];
    }
  }

  return papa[x][0];
}
int main() {
  int i, j;
  scanf("%d", &N);
  for(i=1; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    alist[a].push_back(b);
    alist[b].push_back(a);
  }
  dd[1]=1;
  dfs(1);
  for(j=1; j<17; ++j) {
    for(i=2; i<=N; ++i) {
      papa[i][j] = papa[papa[i][j-1]][j-1];
    }
  }
  scanf("%d", &M);
  for(i=0; i<M; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", lca(x, y));
  }

  return 0;
}
