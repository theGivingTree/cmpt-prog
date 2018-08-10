#include <cstdio>
#include <cfloat>
#include <cmath>
using namespace std;
using LL = long long;
int N, K;
LL a[500], s[501], ss[501];
int main() {
  int i, j;
  scanf("%d %d", &N, &K);
  for(i=0; i<N; ++i) {
    scanf("%lld", a+i);
  }
  for(i=1; i<=N; ++i) {
    s[i] = s[i-1] + a[i-1];
  }
  for(i=1; i<=N; ++i) {
    ss[i] = ss[i-1] + a[i-1]*a[i-1];
  }
  double ans = DBL_MAX;
  for(i=K; i<=N; ++i) {
    for(j=0; j<=N-i; ++j) {
      double kkk = (i*(ss[j+i] - ss[j]) - (s[j+i] - s[j])*(s[j+i] - s[j])) / (1.0*i*i);
      if(ans > kkk) ans = kkk;
    }
  }
  printf("%.10lf\n", sqrt(ans));
  return 0;
}
