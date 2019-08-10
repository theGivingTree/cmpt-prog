#include <cstdio>
using namespace std;
unsigned char gb[19][19];
bool bchk(int x, int y) {
  return x>=0 && x<19 && y>=0 && y<19;
}
int main() {
  int i, j;
  for(i=0; i<19; ++i) {
    for(j=0; j<19; ++j) scanf("%hhd", &gb[i][j]);
  }
  int who = 0, a1, a2;
  for(i=0; i<19; ++i) {
    for(j=0; j<19; ++j) {
      unsigned char b = gb[i][j];
      if(b == 0) continue;
      if((!bchk(i, j-1) || b != gb[i][j-1]) && bchk(i, j+1) && b == gb[i][j+1]) {
        int x = i, y = j+2, cnt=2;
        for(; bchk(x, y) && b == gb[x][y]; ++y) ++cnt;
        if(cnt == 5) who = b, a1=i+1, a2=j+1;
      }
      if((!bchk(i-1, j-1) || b != gb[i-1][j-1]) && bchk(i+1, j+1) && b == gb[i+1][j+1]) {
        int x = i+2, y = j+2, cnt=2;
        for(; bchk(x, y) && b == gb[x][y]; ++x, ++y) ++cnt;
        if(cnt == 5) who = b, a1=i+1, a2=j+1;
      }
      if((!bchk(i-1, j) || b != gb[i-1][j]) && bchk(i+1, j) && b == gb[i+1][j]) {
        int x = i+2, y = j, cnt=2;
        for(; bchk(x, y) && b == gb[x][y]; ++x) ++cnt;
        if(cnt == 5) who = b, a1=i+1, a2=j+1;
      }
      if((!bchk(i-1, j+1) || b != gb[i-1][j+1]) && bchk(i+1, j-1) && b == gb[i+1][j-1]) {
        int x = i+2, y = j-2, cnt=2;
        for(; bchk(x, y) && b == gb[x][y]; ++x, --y) ++cnt;
        if(cnt == 5) who = b, a1=i+5, a2=j-3;
      }
    }
  }
  printf("%d\n", who);
  if(who) printf("%d %d", a1, a2);
  return 0;
}

/*
 * @ @ @
 * @ . 0
 * 3 2 1
 *
 */
