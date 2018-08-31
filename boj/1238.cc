#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int N, M, X;
struct Anode {
  int v, w;
  bool operator<(Anode rhs) const {
    return w > rhs.w;
  }
};
vector<Anode> alist1[1000];
vector<Anode> alist2[1000];
int dis1[1000], dis2[1000];
void dijk(vector<Anode> alist[], int dis[]) {
  bool vis[1000] = {};
  memset(dis, 0x7f, sizeof(int)*N);
  dis[X] = 0;
  priority_queue<Anode> q;

  q.push({X, 0});
  while(!q.empty()) {
    Anode an = q.top(); q.pop();
    int u = an.v;
    if(vis[u]) continue;
    vis[u] = true;
    for(Anode bn: alist[u]) {
      if(!vis[bn.v] && dis[bn.v] > dis[u] + bn.w) {
        q.push({bn.v, dis[bn.v] = dis[u] + bn.w});
      }
    }
  }
}
int main() {
  int i, j;
  scanf("%d %d %d", &N, &M, &X);
  --X;
  for(i=0; i<M; ++i) {
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t); --a, --b;
    alist1[a].push_back({b, t});
    alist2[b].push_back({a, t});
  }
  dijk(alist1, dis1);
  dijk(alist2, dis2);
  int ans = 0;
  for(i=0; i<N; ++i) {
    if(ans < dis1[i] + dis2[i]) {
      ans = dis1[i] + dis2[i];
    }
  }
  printf("%d", ans);
  return 0;
}
