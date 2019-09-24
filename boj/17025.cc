#include <cstdio>
using namespace std;
int N;
char uu[1000][1001];
bool vv[1000][1000];
int ar, ar_x, peri, peri_x;
bool prx(int i, int j) {
  return i>=0 && i<N && j>=0 && j<N && uu[i][j] == '#' ? true : false;
}
void go(int i, int j) {
  if(vv[i][j]) return;
  vv[i][j] = true;
  ++ar_x;
  peri_x += 4;
  if(prx(i+1, j)) {
    --peri_x;
    go(i+1, j);
  }
  if(prx(i, j+1)) {
    --peri_x;
    go(i, j+1);
  }
  if(prx(i-1, j)) {
    --peri_x;
    go(i-1, j);
  }
  if(prx(i, j-1)) {
    --peri_x;
    go(i, j-1);
  }
}
int main() {
  int i, j;
  scanf("%d",&N);
  for(i=0; i<N; ++i) {
    scanf("%s",uu[i]);
  }
  for(i=0; i<N; ++i) {
    for(j=0; j<N; ++j) {
      if(uu[i][j] == '#' && !vv[i][j]) {
        ar_x = 0;
        peri_x = 0;
        go(i, j);
        if(ar < ar_x) ar = ar_x, peri = peri_x;
        else if(ar == ar_x && peri > peri_x) peri = peri_x;
      }
    }
  }
  printf("%d %d", ar, peri);
  return 0;
}
