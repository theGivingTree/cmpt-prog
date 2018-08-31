#include <stdio.h>
typedef long long LL;
int L, W, H, N;
int pool[20];
int main() {
  int i, sh, sh2, j;
  scanf("%d%d%d%d",&L,&W,&H,&N);
  for(i=0; i<N; ++i) {
    int b, c;
    scanf("%d%d",&b,&c);
    pool[b] += c;
  }
  LL ans = 0;
  LL pr = 0, cr = 0, blen;
  for(sh=19; sh>=0; --sh, pr=cr) {
    blen = 1<<sh;
    cr = (L/blen)*(W/blen)*(H/blen);

    LL req = cr - pr*8, preq;
    for(sh2=sh, j=0; sh2>=0 && req>0; --sh2, ++j) {
      preq = req;
      req -= pool[sh2];
      if(req < 0) req = 0;
      pool[sh2] -= preq - req;
      ans += preq - req;
      req<<=3;
    }
    if(req > 0) break;
  }
  printf("%lld", sh<0 ? ans : -1);
  return 0;
}
