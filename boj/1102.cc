#include <cstdio>
using namespace std;
int _popca[256];
void popc_init(void) {
  int i, j, c;
  for(i=0; i<256; ++i) {
    c=0;
    for(j=i; j; j>>=1) c += j&1;
    _popca[i] = c;
  }
}
int popc(unsigned short x) {
  return _popca[x&0xFF] + _popca[x>>8];
}

int N, P;
int tt[16][16];
int dd[1<<16];
int ans;

int main(void) {
  popc_init();

  int i, j;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    for(j=0; j<N; ++j) {
      scanf("%d", &tt[i][j]);
    }
  }
  for(i=0; i<1<<N; ++i) {
    dd[i] = 0x30000000;
  }

  char _buf[17];
  unsigned cstat = 0;
  scanf("%s", _buf);
  for(i=0; i<N; ++i) {
    if(_buf[i] == 'Y') cstat |= 1<<i;
  }
  dd[cstat] = 0;
  scanf("%d", &P);

  unsigned b, bb;
  ans = 0x30000000;
  for(b=cstat; b<1<<N; ++b) {
    if((b & cstat) != cstat) continue;
    for(i=0; i<N; ++i) {
      if(1<<i & cstat || !(1<<i & b)) continue;
      bb = b & ~(1<<i); // bb -> b

      int mm = 0x30000000;
      for(j=0; j<N; ++j) {
        if(j==i || !(1<<j & bb)) continue;
        if(mm > tt[j][i]) mm = tt[j][i];
      }
      if(dd[b] > dd[bb] + mm) dd[b] = dd[bb] + mm;
    }
    if(popc(b) >= P && ans > dd[b]) ans = dd[b];
  }
  if(ans == 0x30000000) ans = -1;
  printf("%d", ans);
  return 0;
}
