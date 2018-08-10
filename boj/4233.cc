#include <cstdio>
#include <vector>
using namespace std;
int const RN_MAX = 31623;
int p, a;
bool iscompo[RN_MAX];
vector<int> primes;
int exp_mod(int a, int b, int M) {
  int ret = 1;
  while(b) {
    if(b&1) {
      ret = 1LL*ret*a%M;
    }
    b>>=1;
    a = 1LL*a*a%M;
  }
  return ret;
}
int gcd(int a, int b) {
  int t;
  while(b) {
    t=b;b=a%b;a=t;
  }
  return a;
}
int main() {
  int i, j;
  for(i=2; i<=RN_MAX; ++i) {
    if(iscompo[i]) continue;
    primes.push_back(i);
    for(j=i*i; j<=RN_MAX; j+=i) {
      iscompo[j] = true;
    }
  }
  while(scanf("%d %d", &p, &a), p) {
    if(exp_mod(a, p, p) != a) {
      puts("no");
      continue;
    }
    if(gcd(a, p) != 1) {
      puts("yes");
      continue;
    }
    int sz = primes.size();
    for(j=0; j<sz; ++j) {
      if(p%primes[j] == 0) break;
    }
    if(j != sz && p != primes[j]) {
      puts("yes");
      continue;
    }
    puts("no");
  }
  return 0;
}
