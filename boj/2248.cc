#include <cstdio>
using namespace std;
unsigned L, N, I;
unsigned cn[32]={0,1};
int popcount(unsigned x) {
  x -= (x>>1)&0x55555555;
  x = (x&0x33333333) + ((x>>2)&0x33333333);
  x = (x + (x>>4))&0x0f0f0f0f;
  return (x*0x01010101) >> 24;
}
void calc_cn() {
  // cn[i] == (n i-1)
  int M=N-L<L?N-L:L;
  for(int i=1; i<=M; ++i) {
    cn[i+1]=cn[i]*(L-i+1)/i;
  }
  for(int i=1; i<=M; ++i) {
    cn[i+1]+=cn[i];
  }
}
void pb(int x, int p) {
  while(p--) putchar((x>>p)&1?'1':'0');
}
int main() {
  scanf("%d %d %d", &N, &L, &I);
  unsigned TTL, i=0, cnt=0, t=0;
  for(; I>0; N=L, L-=cnt) {
    TTL = (1<<L);
    calc_cn();
    for(i=0;;++i, I-=t) {
      t=0;
      cnt = popcount(i);
      if(cnt>L) continue;
      t = TTL-cn[cnt];
      if(I<=t) break;
    }
    pb(i, N-L);
    if(i==0) {
      pb(I-1, L);
      break;
    }
  }
  return 0;
}
