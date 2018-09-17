#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
char map[1000][1001];
int hray[1000][1000];
int vray[1000][1000];
struct Ray {
  int x, y, s;
};
vector<Ray> rayvec;
int main() {
  int i, j, k;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; ++i) scanf("%s", map[i]);
  for(i=0; i<n; ++i) {
    j=0;
    while(j<m) {
      while(j<m && map[i][j] == '.') ++j;
      int jj, cnt=0;
      for(jj=j; jj<m && map[i][jj] == '*'; ++cnt, ++jj);
      int kL = (jj-j+1)/2;
      for(k=0; k<kL; ++k) hray[i][j+k]=k+1;
      for(k=kL; k<jj-j; ++k) hray[i][j+k]=jj-j-k;
      j = jj;
    }
  }
  for(j=0; j<m; ++j) {
    i=0;
    while(i<n) {
      while(i<n && map[i][j] == '.') ++i;
      int ii, cnt=0;
      for(ii=i; ii<n && map[ii][j] == '*'; ++cnt, ++ii);
      int kL = (ii-i+1)/2;
      for(k=0; k<kL; ++k) vray[i+k][j]=k+1;
      for(k=kL; k<ii-i; ++k) vray[i+k][j]=ii-i-k;
      i = ii;
    }
  }

  for(i=0; i<n; ++i) {
    for(j=0; j<m; ++j) {
      int raysz = min(hray[i][j], vray[i][j]);
      if(raysz < 2) continue;
      map[i][j] = '.';
      for(k=1; k<=raysz-1; ++k) {
        map[i+k][j] = '.';
        map[i-k][j] = '.';
        map[i][j+k] = '.';
        map[i][j-k] = '.';
      }
      rayvec.push_back({i+1, j+1, raysz-1});
    }
  }
  for(i=0; i<n; ++i) {
    for(j=0; j<m; ++j) {
      if(map[i][j] == '*') {
        puts("-1");
        return 0;
      }
    }
  }

  printf("%zd\n", rayvec.size());
  for(Ray ray: rayvec) {
    printf("%d %d %d\n", ray.x, ray.y, ray.s);
  }

  return 0;
}
