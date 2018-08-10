#include <stdio.h>
int N, M, ans;
char a[50][51], b[50][51];
int main() {
  int i, j, x, y;
  scanf("%d %d", &N, &M);
  for(i=0; i<N; i++) scanf("%s", a[i]);
  for(i=0; i<N; i++) scanf("%s", b[i]);
  for(i=0; i<N-2; ++i) {
    for(j=0; j<M-2; ++j) {
      if(a[i][j] == b[i][j]) continue;
      for(x=i; x<i+3; ++x) for(y=j; y<j+3; ++y) a[x][y] = '0'+!(a[x][y]-'0');
      ++ans;
    }
    if(a[i][M-2] != b[i][M-2] || a[i][M-1] != b[i][M-1]) {
      ans=-1;
      break;
    }
  }
  for(; i<N; ++i) {
    for(j=0; j<M; ++j) {
      if(a[i][j] != b[i][j]) {
        ans=-1;
        break;
      }
    }
  }
  printf("%d", ans);
}
