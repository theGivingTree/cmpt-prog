#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct P {
  int x, y;
};
int N, M;
bool li[100][100];
bool vis[100][100];
vector<P> wire[100][100];
queue<P> mq;
int ans;
void more_rooms(int x, int y) {
  x+1<N && (li[x+1][y] && !vis[x+1][y]) && (mq.push({x+1, y}), vis[x+1][y]=true);
  y+1<N && (li[x][y+1] && !vis[x][y+1]) && (mq.push({x, y+1}), vis[x][y+1]=true);
  x-1>=0 && (li[x-1][y] && !vis[x-1][y]) && (mq.push({x-1, y}), vis[x-1][y]=true);
  y-1>=0 && (li[x][y-1] && !vis[x][y-1]) && (mq.push({x, y-1}), vis[x][y-1]=true);
}
int main() {
  int i;
  scanf("%d %d", &N, &M);
  for(i=0; i<M; ++i) {
    int x, y, a, b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    --a,--b,--x,--y;
    wire[x][y].push_back({a,b});
  }
  mq.push({0, 0});
  li[0][0] = true;
  vis[0][0] = true;
  ans = 1;
  while(!mq.empty()) {
    P &e = mq.front(); mq.pop();
    
    for(P &n : wire[e.x][e.y]) {
      int x = n.x, y = n.y;
      if(li[x][y]) continue;
      li[x][y] = true;
      ++ans;

      if( (x+1<N && vis[x+1][y])
        || (y+1<N && vis[x][y+1])
        || (x-1>=0 && vis[x-1][y])
        || (y-1>=0 && vis[x][y-1])
      ) {
        mq.push({x, y});
        vis[x][y] = true;
      }
    }

    more_rooms(e.x, e.y);
  }

  printf("%d", ans);
  return 0;
}
