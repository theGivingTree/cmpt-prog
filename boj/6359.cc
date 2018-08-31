#include <cstdio>
using namespace std;
int primes[]={2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97};
void solve() {
  int prl = (sizeof primes)/sizeof(int);
  int i, j;
  int n, ans=1;
  scanf("%d", &n);
  for(i=2; i<=n; ++i) {
    int x=i;
    int cnt=1;
    for(j=0; j<prl && x>1; ++j) {
      int cc=1;
      while(x%primes[j] == 0) x/=primes[j], ++cc;
      cnt*=cc;
      if(cnt%2==0) {
        break;
      }
    }
    if(cnt&1) ++ans;
  }
  printf("%d\n", ans);
}
int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) solve();
}
