#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
  int t;
  while(b) {
    t=a;a=b;b=t%b;
  }
  return a;
}
int isprime[3873];
vector<int> primes, pmins, ppow;
int n, aa[300000], bb[300000];
int main() {
  int i ,j;
  for(i=2; i<3873; ++i) isprime[i] = true;
  for(i=2; i<3873; ++i) {
    if(!isprime[i]) continue;
    primes.push_back(i);
    for(j=i*i; j<3873; j+=i) isprime[j] = false;
  }
  int pn = primes.size();
  pmins.resize(pn);
  ppow.resize(pn);
  for(i=0; i<pn; ++i) pmins[i] = 50;

  scanf("%d", &n);
  int gg = 0;
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    aa[i] = a;
    gg = gcd(a, gg);
    bb[i] = a;
  }
  for(j=0; j<pn; ++j) {
    int pcnt = 0;
    int p = primes[j];
    while(gg%p == 0) {gg/=p; ++pcnt; }
    if(pmins[j] > pcnt) pmins[j] = pcnt;
  }
  for(i=0; i<pn; ++i) {
    int p = primes[i], r = 1;
    for(j=0; j<pmins[i]; ++j) r*=p;
    ppow[i] = r;
  }
  int ans = 0x7fFFffFF;
  for(i=0; i<pn; ++i) {
    int p = primes[i];
    long long pp = 1LL * ppow[i] * p;
    int cnt = 0;
    for(j=0; j<n; ++j) {
      if(aa[j] % pp != 0) ++cnt;
    }
    if(ans > cnt) ans = cnt;
  }
  sort(bb, bb+n);
  i=0;
  while(i<n && bb[i] == 1) ++i;
  while(i<n) {
    j=i+1;
    while(j<n && bb[i] == bb[j]) ++j;
    if(j-i == n) break;
    if(ans > n-(j-i)) ans = n-(j-i);
    i=j;
  }
  if(ans == n) printf("-1");
  else printf("%d", ans);
  return 0;
}
