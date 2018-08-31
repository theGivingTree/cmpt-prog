#include <cstdio>
int d[11][221];
int N, M, X;
int main() {
  int i,j,k;
  scanf("%d%d%d", &N,&M,&X);
  d[1][0]=1;
  for(i=1;i<N;++i) {
    for(j=0; j<=M; ++j) {
      for(k=0;k<=j/i;++k) d[i+1][j] += d[i][j-k*i];
    }
  }
  j=1;
  for(i=N; i>=1; --i) {
    for(; X-d[i][M-j*i]>0; X-=d[i][M-j*i], ++j);
    printf("%d ", j);
    M-=j;
  }
}
