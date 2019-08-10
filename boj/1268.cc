#include <cstdio>
using namespace std;
int N, v[5][1000], cc[1000];
int main() {
  scanf("%d", &N);
  for(int j=0; j<N; ++j) {
    for(int i=0; i<5; ++i) {
      scanf("%d", &v[i][j]);
    }
  }
  for(int j=0; j<N-1; ++j) {
    for(int jj=j+1; jj<N; ++jj) {
      int i;
      for(i=0; i<5 && v[i][j] != v[i][jj]; ++i);
      if(i<5) {
        ++cc[j], ++cc[jj];
      }
    }
  }
  int ans = 0;
  for(int j=1; j<N; ++j) {
    if(cc[ans] < cc[j]) {
      ans = j;
    }
  }
  printf("%d", ans+1);
  return 0;
}
