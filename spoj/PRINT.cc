#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int const SQN = 46340;
bool isprime[SQN+1];
vector<int> primes; // only odd primes
void prime_init() {
  int i, j;
  memset(isprime+2, 1, (sizeof isprime)-2);
  int nprimes = 0;
  for(i=2; i<=SQN; ++i) {
    if(!isprime[i]) continue;
    ++nprimes;
    for(j=i*i; j<=SQN; j+=i) isprime[j] = false;
  }
  primes.resize(nprimes-1);
  j=0;
  for(i=3; i<=SQN; ++i) {
    if(isprime[i]) primes[j++] = i;
  }
}
void solve(unsigned L, unsigned U) {
  if(L<=2 && U>=2) printf("%d\n", 2);
  if(~L&1) ++L;
  if(~U&1) --U;
  // if(L>U) break;

  bool exit = false;
  unsigned stride = 2*(SQN-1), iU = L+stride;
  do {
    if(iU >= U) {
      iU = U;
      exit = true;
    }
    memset(isprime, 1, sizeof isprime);

    for(int p: primes) {
      unsigned A, Aidx, inc;

      A=(L+p-1)/p*p;
      if(A < p*p) A = p*p;
      if(~A&1) A += p;
      Aidx = A-L>>1;
      inc = 2*p;

      for(; A<=iU; A+=inc, Aidx+=p) {
        isprime[Aidx] = false;
      }
    }

    int toI = iU-L>>1;
    for(int i=0; i<=toI; ++i) {
      if(isprime[i]) {
        printf("%d\n", L+2*i);
      }
    }

    L = iU+2;
    iU = L+stride;
  } while(!exit);
}
int main() {
  prime_init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int L, U;
    scanf("%d%d", &L, &U);
    solve(L, U);
  }
}
