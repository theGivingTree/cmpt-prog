#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
uLL const MOD = 1ULL<<32;
int const SQP = 17320;

bool isprime[SQP+1];
int chkConst = 1;
vector<int> primes;

void prime_init() {
  int i, j;
  for(i=2; i<=SQP; ++i) isprime[i] = true;
  for(i=2; i<=SQP; ++i) {
    if(!isprime[i]) continue;
    chkConst *= i;
    primes.push_back(i);
    for(j=i*i; j<=SQP; j+=i) {
      isprime[j] = false;
    }
  }
}

int gcd(int a, int b) {
  int t;
  while(b) {
    t=b;b=a%b;a=t;
  }
  return a;
}

LL ff(int n, int A, int B, int C, int D, int p) {
  LL Ax3 = (1LL*(A*p)%MOD * 1LL*(p*p)%MOD) % MOD;
  LL Bx2 = (1LL*(B*p)%MOD * p) % MOD;
  LL Cx = 1LL*C*p % MOD;

  LL val = (Ax3 + Bx2 + Cx + D) % MOD;

  uLL sum = 0;
  for(LL q=n/p; q>0; q/=p) {
    sum = (sum + q) % MOD;
  }

  return (uLL(sum) * uLL(val)) % MOD;
}

int main() {
  prime_init();
  int i, j;
  int n, A, B, C, D;
  cin >> n >> A >> B >> C >> D;

  uLL ans = 0;
  if(n <= SQP) {
    int sz = primes.size();
    for(i=0; i<sz && primes[i] <= n; ++i) {
      ans = (ans + ff(n, A, B, C, D, primes[i])) % MOD;
    }
  }
  else {
    int sz = primes.size();
    for(i=0; i<sz; ++i) {
      ans = (ans + ff(n, A, B, C, D, primes[i])) % MOD;
    }

    for(i=SQP+1; i<=n; i+=2) {
      if(gcd(i, chkConst) == 1) {
        ans = (ans + ff(n, A, B, C, D, i)) % MOD;
      }
    }
  }

  cout << ans;
}
