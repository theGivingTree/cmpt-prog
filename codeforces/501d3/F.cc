#include <cstdio>
#include <algorithm>
int n, sf, sfmin=5000;
int dp[200][201];
int main() {
  int i, j;
  char ch;
  scanf("%d ", &n);
  while((ch=getchar())!='\n' && ch!=EOF) {
    if(ch == '(') ++sf
    else --sf;
    if(sfmin > sf) sfmin = sf;
  }
  dp[0][100+1] = 1;
  dp[0][100-1] = 1;
  for(i=1; i<2*n; ++i) {
    int up = min(i+2, n);
    for(j=0; j<=up; ++j) {
      dp[i][100+j] = dp[i][100-j];
      dp[i][100-j];
    }
  }
  return 0;
}
