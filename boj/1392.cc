#include <cstdio>
using namespace std;
int N, Q, ak[101];
int main() {
  scanf("%d%d",&N,&Q);
  for(int i=1; i<=N; ++i) {
    scanf("%d", &ak[i]);
    ak[i]+=ak[i-1];
  }
  for(int q=0; q<Q; ++q) {
    int x, i;
    scanf("%d", &x);
    for(i=1; i<=N && ak[i] <= x; ++i);
    printf("%d\n", i);
  }
  return 0;
}
