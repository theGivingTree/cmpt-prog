#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
int N, w[16][16], dp[1<<15][16], clz[1<<15];
int main() {
  int i, j, S, Si, Sii, Sj, Sjj, p1, p2;
  struct stat rstat;
  fstat(0, &rstat);
  int rsize = rstat.st_size;
  char *ptr = (char *)mmap(0,rsize,PROT_READ,MAP_PRIVATE,0,0);
  N = strtoul(ptr, &ptr, 10);
  for(i=0; i<N; ++i) for(j=0; j<N; ++j) w[i][j]=strtoul(ptr, &ptr, 10);
  for(i=1; i<N; ++i) dp[0][i-1] = w[0][i];
  for(i=0; i<N-1; ++i) clz[1<<i]=i;
  for(S=1; S<1<<N-1; ++S) {
    for(Sj=S; Sj; Sj=Sjj) {
      Sjj=Sj&(Sj-1);
      j=clz[Sj^Sjj]+1;
      p2=dp[S^Sj^Sjj][j-1];
      if(!p2) continue;
      for(Si=~S&(1<<N-1)-1; Si; Si=Sii) {
        Sii=Si&(Si-1);
        i=clz[Si^Sii]+1;
        p1=w[j][i];
        if(!p1) continue;
        if(!dp[S][i-1] || dp[S][i-1] > p1+p2) dp[S][i-1] = p1+p2;
      }
    }
  }
  int ans=0x7fFFffFF;
  for(i=0; i<N-1; ++i) {
    int p1=w[i+1][0], p2=dp[(1<<N-1)-1 ^ 1<<i][i];
    if(p1 && p2 && ans>p1+p2) ans = p1+p2;
  }
  char buf[8];
  for(i=7;ans;--i,ans/=10) buf[i]=ans%10+'0';
  ++i;
  write(1, buf+i, 8-i);
  return 0;
}
