#include <cstdio>
using namespace std;
using LL = unsigned long long;
LL K; LL fibo[88]={0,1};
int main() {
  int i, j;
  for(i=2; i<=87; ++i) fibo[i]=fibo[i-1]+fibo[i-2];
  scanf("%lld",&K);
  for(i=1; fibo[i] < K; ++i) K-=fibo[i];
  do {
    --K;
    for(j=0; fibo[j] < K; ++j) K-=fibo[j];
    putchar('1');
    for(--i; i>j; --i) putchar('0');
  } while(K);
}
