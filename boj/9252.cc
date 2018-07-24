#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char sa[1001], sb[1001], lcs[1001];
int alen, blen, d[2][1001];
bool kk[1000][1000];
int main() {
  int i, j;
  scanf("%s %s", sa, sb);
  alen = strlen(sa);
  blen = strlen(sb);
  for(i=0; i<alen; ++i) {
    for(j=0; j<blen; ++j) {
      int r = d[i&1][j+1];
      if(r < d[~i&1][j]) {
        kk[i][j] = true;
        r=d[~i&1][j];
      }
      if(sa[i] == sb[j]) r = max(r, d[i&1][j]+1);
      d[~i&1][j+1] = r;
    }
  }
  int ans = d[alen&1][blen];
  printf("%d\n", ans);
  i=alen-1, j=blen-1;
  while(ans) {
    if(sa[i] == sb[j]) lcs[--ans] = sa[i], --i, --j;
    else if(kk[i][j]) --j;
    else --i;
  }
  puts(lcs);
  return 0;
}
