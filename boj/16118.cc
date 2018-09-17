#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
struct Eg {
  int v, w;
};
vector<Eg> gfox[4001], gwolf[8001];
bool vis[8001];
int disfox[4001], diswolf[8001];
int N, M;
void dijk(int n, vector<Eg> graph[], bool vis[], int dis[]) {
  int i, j;
  for(i=0; i<n; ++i) {
    int u = 0, udis = INT_MAX, v, w;
    for(j=1; j<=n; ++j) {
      if(!vis[j] && udis > dis[j]) {
        u = j; udis = dis[j];
      }
    }
    vis[u] = true;
    int sz = graph[u].size();
    for(j=0; j<sz; ++j) {
      v = graph[u][j].v;
      w = graph[u][j].w;
      if(!vis[v] && dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
      }
    }
  }
}
int main() {
  int i, j;
  scanf("%d%d",&N,&M);
  for(i=0; i<M; ++i) {
    int a, b, d;
    scanf("%d%d%d", &a,&b,&d);
    d*=2;
    gfox[a].push_back({b, d});
    gfox[b].push_back({a, d});
    gwolf[a].push_back({N+b, d/2});
    gwolf[N+a].push_back({b, d*2});
    gwolf[b].push_back({N+a, d/2});
    gwolf[N+b].push_back({a, d*2});
  }
  for(i=1; i<=N; ++i) disfox[i] = INT_MAX;
  disfox[1] = 0;
  dijk(N, gfox, vis, disfox);
  for(i=1; i<=2*N; ++i) diswolf[i] = INT_MAX;
  diswolf[1] = 0;
  memset(vis+1, 0, N);
  dijk(2*N, gwolf, vis, diswolf);
  int ans = 0;
  for(i=1; i<=N; ++i) {
    int a, b;
    a = disfox[i];
    b = min(diswolf[i], diswolf[N+i]);
    if(a == INT_MAX && b == INT_MAX) continue;
    if(a < b) ++ans;
  }
  printf("%d", ans);
  return 0;
}
