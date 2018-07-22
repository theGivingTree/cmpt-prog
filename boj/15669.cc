#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;
int N, M;
vector<int> alist[100000];
int dp_even[100000], dp_odd[100000], dp2_even[100000];
void dfs(int u, int pu) {
  for(int v: alist[u]) {
    if(v == pu) continue;
    dfs(v, u);
    dp_even[u] += dp_odd[v];
    dp_odd[u] += dp_even[v] + 1;
  }
}
void dfs2(int u, int pu, int odd) {
  for(int v: alist[u]) {
    if(v == pu) continue;
    dp2_even[v] = (dp_odd[u] - (dp_even[v]+1)) + odd;
    dfs2(v, u, N-(dp_even[v]+dp_odd[v]+1)-dp2_even[v]);
  }
}
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for(i=1; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    alist[a].push_back(b);
    alist[b].push_back(a);
  }
  dfs(0, -1);
  dfs2(0, -1, 0);
  for(i=0; i<M; ++i) {
    int U, V, C, e, o, e2, o2;
    scanf("%d %d %d", &U, &V, &C), --U, --V;
    if(dp_even[U] < dp_odd[V]) swap(U, V);
    e=dp_even[V]+1, o=dp_odd[V], e2=dp2_even[V], o2=N-(e+o)-e2;
    LL ans;
    if(C) {
      // odd
      ans = 1LL*o*e2 + 1LL*e*o2;
    }
    else {
      // even
      ans = 1LL*e*e2 + 1LL*o*o2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
