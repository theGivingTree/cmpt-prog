#include <cstdio>
#include <queue>
using namespace std;
int N;
int f[100000];
int deg[100000];
queue<int> qq;
int main() {
  int i;
  scanf("%d",&N);
  for(i=0; i<N; ++i) {
    int a;
    scanf("%d",&a);
    f[i]=a-1;
    ++deg[a-1];
  }
  for(i=0; i<N; ++i) {
    if(deg[i] == 0) qq.push(i);
  }
  while(!qq.empty()) {
    queue<int> qqx;
    while(!qq.empty()) {
      int e = qq.front(); qq.pop();
      --deg[f[e]];
      if(deg[f[e]] == 0) {
        qqx.push(f[e]);
      }
    }
    qq.swap(qqx);
  }
  int ans = 0;
  for(i=0; i<N; ++i) {
    if(deg[i]>0) ++ans;
  }
  printf("%d", ans);
  return 0;
}
