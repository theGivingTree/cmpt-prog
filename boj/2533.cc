#include <cstdio>
#include <vector>
using namespace std;
int const MAX_N = 1000000;
int N, e[MAX_N+1], ne[MAX_N+1];
vector<int> vv[MAX_N+1];
void go(int p, int c) {
  int i, len=vv[c].size();
  if(p!=0 && len==1) {
    e[c]=1;
    ne[c]=0;
    return;
  }
  e[c]=1, ne[c]=0;
  for(i=0; i<len; ++i) {
    int n=vv[c][i];
    if(n==p) continue;
    go(c, n);
    e[c] += e[n]<ne[n]?e[n]:ne[n];
    ne[c] += e[n];
  }
  return;
}
int main() {
  scanf("%d", &N);
  for(int i=1; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    vv[a].push_back(b);
    vv[b].push_back(a);
  }
  vv[1].push_back(0);
  go(0, 1);
  printf("%d", e[1]<ne[1]?e[1]:ne[1]);
  return 0;
}
