#include <cstdio>
using namespace std;
int const MOD = 1'000'000'000;
int N, d[2][12];
int main() {
  int i, j;
  for(i=2; i<=10; ++i) d[1][i]=1;
  scanf("%d", &N);
  for(i=2; i<=N; ++i) {
    for(j=1; j<=10; ++j) d[i&1][j]=(d[~i&1][j-1]+d[~i&1][j+1])%MOD;
  }
  int ans=0;
  for(i=1; i<=10; ++i) ans+=d[N&1][i], ans%=MOD;
  printf("%d", ans);
}
