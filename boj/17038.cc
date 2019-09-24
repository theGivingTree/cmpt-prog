#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, bool>> alist[100000];
bool vis[100000];
bool mk[100000];
bool go(int x) {
  queue<int> qq, nqq;
  qq.push(x);
  while(!qq.empty()) {
    while(!qq.empty()) {
      int e = qq.front(); qq.pop();
      for(auto &ff: alist[e]) {
        int f = ff.first;
        bool S = ff.second;
        if(vis[f]) {
          if(mk[f] != (mk[e] == S)) return false;
          continue;
        }
        vis[f] = true;
        mk[f] = (mk[e] == S);
        nqq.push(f);
      }
    }
    qq.swap(nqq);
  }
  return true;
}
int main() {
  int i;
  int N, M;
  scanf("%d%d",&N,&M);
  for(i=0; i<M; ++i) {
    char ch;
    int a, b;
    scanf(" %c%d%d",&ch, &a, &b), --a, --b;
    alist[a].push_back({b, ch == 'S'});
    alist[b].push_back({a, ch == 'S'});
  }
  int ans = 0;
  for(i=0; i<N; ++i) {
    if(!vis[i]) {
      vis[i] = true;
      int a = go(i);
      if(!a) {
        puts("0");
        return 0;
      }
      ++ans;
    }
  }
  putchar('1');
  for(i=0; i<ans; ++i) putchar('0');
  return 0;
}
