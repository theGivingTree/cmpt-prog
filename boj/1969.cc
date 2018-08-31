#include <stdio.h>
int n, m;
char ss[1000][51];
int main() {
  int i, j, k;
  scanf("%d%d", &n,&m);
  for(i=0;i<n;++i) {
    scanf("%s", ss[i]);
  }
  int ans=0;
  for(j=0;j<m;++j) {
    int cc[4] = {};
    for(i=0; i<n; ++i) {
      if(ss[i][j] == 'A') ++cc[0];
      else if(ss[i][j] == 'C') ++cc[1];
      else if(ss[i][j] == 'G') ++cc[2];
      else ++cc[3];
    }
    int x=0;
    for(k=1;k<4;++k) {
      if(cc[x] < cc[k]) {
        x=k;
      }
    }
    ans += n-cc[x];
    if(x==0) putchar('A');
    else if(x==1) putchar('C');
    else if(x==2) putchar('G');
    else putchar('T');
  }
  printf("\n%d", ans);
  return 0;
}
