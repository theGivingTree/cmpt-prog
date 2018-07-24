#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, tc;
char row1[5001], row2[5001];
int len1, len2, cnt1[5001][26], cnt2[5001][26];
int D[2][5001];
int calcDelta(int i, int j, char c) {
  int ret=0, ci = c-'A', before = cnt1[i][ci] + cnt2[j][ci];
  if(before == 1) ret -= i+j;
  if(before == cnt1[len1][ci] + cnt2[len2][ci]) ret += i+j;
  return ret;
}
int main() {
  int i, j;
  scanf("%d", &T);
  for(tc=1; tc<=T; ++tc) {
    scanf("%s %s", row1, row2);
    len1 = strlen(row1);
    len2 = strlen(row2);

    for(i=0; i<len1; ++i) {
      memcpy(cnt1[i+1], cnt1[i], sizeof(int)*26);
      ++cnt1[i+1][row1[i]-'A'];
    }
    for(i=0; i<len2; ++i) {
      memcpy(cnt2[i+1], cnt2[i], sizeof(int)*26);
      ++cnt2[i+1][row2[i]-'A'];
    }

    D[0][0] = 0;
    for(j=1; j<=len2; ++j) D[0][j] = D[0][j-1] + calcDelta(0, j, row2[j-1]);

    for(i=1; i<=len1; ++i) {
      D[i&1][0] = D[~i&1][0] + calcDelta(i, 0, row1[i-1]);
      for(j=1; j<=len2; ++j) {
        int d1 = calcDelta(i, j, row1[i-1]);
        int d2 = calcDelta(i, j, row2[j-1]);
        D[i&1][j] = min(D[~i&1][j] + d1, D[i&1][j-1] + d2);
      }
    }

    printf("%d\n", D[len1&1][len2]);
  }
}
