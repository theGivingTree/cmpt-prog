#include <cstdio>
using namespace std;
int n, tt[8];
int main() {
  int i, j;
  for(i=0; i<8; ++i) tt[i] = 10000000;
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    unsigned char type = 0;
    int c; char rr[4];
    scanf("%d %s", &c, rr);
    for(j=0; rr[j]; ++j) {
      char ch = rr[j];
      if(ch == 'A') type |= 1<<2;
      else if(ch == 'B') type |= 1<<1;
      else type |= 1;
    }
    if(tt[type] > c) tt[type] = c;
  }
  if(tt[6] > tt[2]+tt[4]) tt[6] = tt[2]+tt[4];
  if(tt[5] > tt[1]+tt[4]) tt[5] = tt[1]+tt[4];
  if(tt[3] > tt[1]+tt[2]) tt[3] = tt[1]+tt[2];
  if(tt[7] > tt[1]+tt[6]) tt[7] = tt[1]+tt[6];
  if(tt[7] > tt[2]+tt[5]) tt[7] = tt[2]+tt[5];
  if(tt[7] > tt[4]+tt[3]) tt[7] = tt[4]+tt[3];
  if(tt[7] > tt[3]+tt[5]) tt[7] = tt[3]+tt[5];
  if(tt[7] > tt[6]+tt[5]) tt[7] = tt[6]+tt[5];
  if(tt[7] > tt[6]+tt[3]) tt[7] = tt[6]+tt[3];
  if(tt[7] == 10000000) tt[7] = -1;
  printf("%d", tt[7]);
}
