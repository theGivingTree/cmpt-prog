#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// isprime[i]; `i`의 소수여부
// fprime[i]: `i`를 합성수라고 판별한 첫번째 소수
void prime_proc(int N, vector<bool>& isprime, vector<int>& fprime) {
  int i;
  long long j;
  isprime[0] = false;
  for(i=1; i<=N; ++i) isprime[i] = true;
  for(i=0; i<=N; ++i) fprime[i] = 0;
  for(i=2; i<=N; ++i) {
    if(!isprime[i]) continue;
    // `i`는 소수임
    fprime[i] = i;
    for(j=1LL*i*i; j<=N; j+=i) {
      isprime[j] = false;
      if(fprime[j] == 0) {
        fprime[j] = i;
      }
    }
  }
}

// swap 대신 임시변수 t 를 쓸 수도 있음.
tuple<int, int, int> xgcd(int a, int b) {
    int q, r0, r1, s0, t0, s1, t1;
    r0=a, r1=b;
    s0=1, s1=0;
    t0=0, t1=1;
    while(r1 != 0) {
        q = r0/r1;

        r0 = r0%r1;
        swap(r0, r1);
        s0 = s0 - q*s1;
        swap(s0, s1);
        t0 = t0 - q*t1;
        swap(t0, t1);
    }

    return make_tuple(r0, s0, t0);
    // r0: a, b의 최대공약수
    // s0, t0: 베주 계수
}

int main() {
  int N = 100000;
  vector<bool> isprime(N+1);
  vector<int> fprime(N+1);
  prime_proc(N, isprime, fprime);

  int a;
  scanf("%d", &a);
  if(a>N) return 0;

  while(a>1) {
    printf("%d\n", fprime[a]);
    a/=fprime[a];
  }
  
  return 0;
}
