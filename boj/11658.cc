#include <cstdio>
using namespace std;
int N, M, mat[1025][1025], aa[1025][1025];
void build1d(int a) {
  int i, j;
  for(i=1; i<=N; ++i) {
    j = i+(i&-i);
    if(j>N) continue;
    mat[a][j] += mat[a][i];
  }
}
void build2d() {
  int i, j, k;
  for(i=1; i<=N; ++i) build1d(i);
  for(i=1; i<=N; ++i) {
    j = i+(i&-i);
    if(j>N) continue;
    for(k=1; k<=N; ++k) {
      mat[j][k] += mat[i][k];
    }
  }
}
void update(int x, int y, int v) {
  int t = v;
  v -= aa[x][y];
  aa[x][y] = t;
  while(x<=N) {
    int yy=y;
    while(yy<=N) {
      mat[x][yy] += v;
      yy+=yy&(-yy);
    }
    x+=x&(-x);
  }
}
int query(int x, int y) {
  int sum=0;
  while(x>0) {
    int yy=y;
    while(yy>0) {
      sum += mat[x][yy];
      yy-=yy&(-yy);
    }
    x-=x&(-x);
  }
  return sum;
}
int rquery(int x1, int y1, int x2, int y2) {
  return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for(i=1; i<=N; ++i) {
    for(j=1; j<=N; ++j) {
      scanf("%d", &mat[i][j]);
      aa[i][j] = mat[i][j];
    }
  }
  build2d();
  for(i=0; i<M; ++i) {
    int w;
    scanf("%d", &w);
    if(w) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      printf("%d\n", rquery(x1, y1, x2, y2));
    }
    else {
      int x, y, c;
      scanf("%d %d %d", &x, &y, &c);
      update(x, y, c);
    }
  }
  return 0;
}
