#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
using LL = long long;
LL n, k;
bool iscompo[1000001];
vector<int> primes;
void primeinit() {
  for(int i=2; i<=1000000; ++i) {
    if(iscompo[i]) continue;
    primes.push_back(i);
    if(1LL*i*i > 1000000) continue;
    for(int j=i*i; j<=1000000; j+=i) {
      iscompo[j] = true;
    }
  }
}
LL facto(LL n, LL p) {
  LL f=0;
  LL pp = 1;
  do {
    pp*=p;
    f += n/pp;
  } while(pp <= n/p);
  return f;
}
void solve() {
  scanf("%lld %lld", &n, &k);
  LL ans = LLONG_MAX;
  int e;
  LL f;
  for(int p: primes) {
    e=0;
    while(k%p == 0) k/=p, ++e;
    if(e == 0) continue;

    f=facto(n, p);
    if(ans > f/e) ans = f/e;
    if(ans == 0) break;
    if(k == 1) break;
  }
  if(ans != 0 && k>1) {
    e=1, f=facto(n, k);
    if(ans > f/e) ans = f/e;
  }
  printf("%lld\n", ans);
  return;
}
int main() {
  int T;
  primeinit();
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
