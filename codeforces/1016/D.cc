#include <cstdio>
#include <algorithm>
using namespace std;
int r, c;
int rx[100], cx[100];
int mat[100][100];
int main() {
  int bc, i, j;
  scanf("%d %d", &r, &c);
  for(i=0; i<r; ++i) scanf("%d", rx+i);
  for(j=0; j<c; ++j) scanf("%d", cx+j);

  for(bc=0; bc<30; ++bc) {
    int bitr=0, bitc=0;
    for(i=0; i<r; ++i) {
      int bit = (rx[i]>>bc)&1;
      bitr^=bit;
    }
    for(j=0; j<c; ++j) {
      int bit = (cx[j]>>bc)&1;
      bitc^=bit;
    }
    if(bitr != bitc) {
      puts("NO");
      return 0;
    }

    i=0, j=0;
    while(true) {
      while(i<r && (rx[i]>>bc&1) == 0) ++i;
      while(j<c && (cx[j]>>bc&1) == 0) ++j;
      if(i<r && j<c) {
        mat[i][j] |= 1<<bc;
        ++i, ++j;
      }
      else break;
    }

    for(; i<r; ++i) {
      if(rx[i]>>bc&1) {
        mat[i][0] |= 1<<bc;
      }
    }
    for(; j<c; ++j) {
      if(cx[j]>>bc&1) {
        mat[0][j] |= 1<<bc;
      }
    }
  }

  puts("YES");
  for(i=0; i<r; ++i) {
    for(j=0; j<c; ++j) {
      printf("%d ", mat[i][j]);
    }
    puts("");
  }
}
