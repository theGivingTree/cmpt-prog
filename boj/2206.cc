#include <cstdio>
#include <queue>
using namespace std;
struct PP {
  int x, y;
  bool f;
};
int N, M;
char mm[1002][1002];
bool visit1[1000][1000];
bool visit2[1000][1000];
void go() {
  int i;
  queue<PP> q;
  q.push({1, 1, true});
  for(int dis=1; !q.empty(); ++dis) {
    int sz = q.size();
    for(i=0; i<sz; ++i) {
      PP pp = q.front(); q.pop();
      int x = pp.x, y = pp.y;
      bool f = pp.f;
      if(x==0 || y==0 || x==N+1 || y==M+1) continue;
      if(f) {
        if(visit1[x-1][y-1]) continue;
        if(mm[x][y] == '1') f = false;
        visit1[x-1][y-1] = true;
      }
      else {
        if(visit2[x-1][y-1] || mm[x][y] == '1') continue;
        visit2[x-1][y-1] = true;
      }
      if(x==N && y==M) {
        printf("%d", dis);
        return;
      }
      q.push({x+1, y, f});
      q.push({x-1, y, f});
      q.push({x, y+1, f});
      q.push({x, y-1, f});
    }
  }
  puts("-1");
}
int main() {
  int i;
  scanf("%d %d", &N, &M);
  for(i=1; i<=N; ++i) scanf("%s", mm[i]+1);
  go();
  return 0;
}
