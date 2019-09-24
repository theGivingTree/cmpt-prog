#include <cstdio>
using namespace std;
int deg[100000];
int main() {
  int N, i;
  scanf("%d",&N);
  for(i=1; i<N; ++i) {
    int a, b;
    scanf("%d%d", &a,&b), --a,--b;
    ++deg[a], ++deg[b];
  }
  int ans = 0;
  for(i=0; i<N; ++i) {
    if(ans < deg[i]+1) ans = deg[i]+1;
  }
  printf("%d", ans);
  return 0;
}
