#include <stdio.h>
#include <string.h>
int N, m, i, j;
char chaek[1000][51];
int cnt[1000];
int main() {
  scanf("%d", &N);
  for(i=0; i<N; i++) {
    scanf("%s", chaek[m]);
    for(j=0; j<m; j++) {
      if(strcmp(chaek[m], chaek[j]) == 0) {
        cnt[j]++;
        break;
      }
    }
    if(j==m) m++;
  }
  int ii, MM=-1;
  for(j=0; j<m; j++) if(MM < cnt[j]) {
    MM = cnt[j];
    ii = j;
  }
  for(j=ii+1; j<m; j++) {
    if(MM == cnt[j]) {
      if(strcmp(chaek[ii], chaek[j]) > 0) ii = j;
    }
  }
  puts(chaek[ii]);
  return 0;
}

