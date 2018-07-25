#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> alist[101];
bool visit[101];
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for(i=0; i<M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    alist[a].push_back(b);
    alist[b].push_back(a);
  }

  int ans = 0;
  queue<int> q;
  q.push(1);
  visit[1]=true;
  while(!q.empty()) {
    int iter = q.size();
    for(i=0; i<iter; ++i) {
      int u = q.front();q.pop();
      ++ans;
      for(int v: alist[u]) {
        if(visit[v]) continue;
        visit[v] = true;
        q.push(v);
      }
    }
  }
  printf("%d", ans-1);
}
