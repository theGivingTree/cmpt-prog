#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int cc[52][52];
int ff[52][52];
int ww[52];
vector<int> alist[52];
int level[52];

bool bfs() {
  memset(level, 0, sizeof level);
  queue<int> q;
  q.push(0);
  level[0] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int v: alist[u]) {
      if(level[v] == 0 && cc[u][v] - ff[u][v] > 0) {
        level[v] = level[u] + 1;
        q.push(v);
      }
    }
  }

  return level[25] > 0;
}

int dfs(int u, int minVal) {
  if(u == 25) return minVal;

  int sz = alist[u].size(), v;
  for(int &i = ww[u]; i<sz; ++i) {
    v = alist[u][i];
    if(level[v] != level[u]+1 || cc[u][v] - ff[u][v] == 0) continue;
    int mf = dfs(v, min(minVal, cc[u][v] - ff[u][v]));
    if(mf > 0) {
      ff[u][v] += mf;
      ff[v][u] -= mf;
      return mf;
    }
  }

  return 0;
}

int rel(char u) {
  if(u < 'a') u -= 'A';
  else u = u-'a'+26;
  return u;
}

int main() {
  int N;
  int i, j;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    int u, v;
    int w;
    scanf(" %c %c %d", &u, &v, &w);
    u = rel(u);
    v = rel(v);
    alist[u].push_back(v);
    alist[v].push_back(u);
    cc[u][v] += w;
    cc[v][u] += w;
  }

  int ans = 0;
  while(bfs()) {
    memset(ww, 0, sizeof ww);
    int flow;
    while((flow = dfs(0, 0x7fFFffFF)) > 0) ans += flow;
  }

  printf("%d", ans);
  return 0;
}
