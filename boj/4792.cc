#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int n, m, K;
bool mat[1001][1001];
bool isblue[1001][1001];
bool bluedis[1001];
bool vis[1001], dis[1001];
bool partial(int&X, int flag) {
  int i, j, k;
  for(i=0; i<X; ++i) {
    int u=n+1;
    for(j=1; j<=n; ++j) {
      if(dis[j] && !vis[j]) {
        u = j;
        if(bluedis[u] && !flag) break;
      }
    }
    if(!flag && u<=n && !bluedis[u]) ++X;
    if(u>n || X>n) {
      puts("0");
      return true;
    }
    vis[u] = true;
    for(k=1; k<=n; ++k) {
      if(mat[k][u] && !vis[k]) {
        if(!dis[k] || (isblue[k][u] && !flag)) {
          if(flag && isblue[k][u]) continue;
          dis[k] = true;
          bluedis[k] = isblue[k][u];
        }
      }
    }
  }
  return false;
}
bool solve() {
  int i;
  scanf("%d%d%d", &n,&m,&K);
  if(n == 0) return false;
  memset(mat+1, 0, 1001*n);
  memset(isblue+1, 0, 1001*n);
  for(i=0; i<m; ++i) {
    char c;
    int f,t;
    scanf(" %c %d %d", &c, &f, &t);
    mat[f][t] = true;
    mat[t][f] = true;
    isblue[f][t] = c == 'B';
    isblue[t][f] = c == 'B';
  }
  memset(bluedis, 0, n+1);
  memset(dis, 0, n+1);
  memset(vis, 0, n+1);

  dis[1] = true;
  bluedis[1] = true;
  int X;
  X = K+1;
  if(partial(X, 0)) return true;
  X = n-X;
  if(partial(X, 1)) return true;

  puts("1");
  return true;
}

int main() {
  while(solve());
  return 0;
}
