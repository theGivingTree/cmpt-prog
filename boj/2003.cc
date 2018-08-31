#include <cstdio>
using namespace std;
int N, M, aa[10000];
int main() {
  int i, j;
  scanf("%d%d", &N,&M);
  for(i=0; i<N; ++i) scanf("%d", aa+i);
  int ans = 0;
  int cs = 0;
  i=0, j=0;
  while(i<N && !(cs<M && j==N)) {
    if(cs < M) cs += aa[j++];
    else {
      if(cs == M) ++ans;
      cs -= aa[i++];
    }
  }
  printf("%d", ans);
  return 0;
}
