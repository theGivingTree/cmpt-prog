#include <cstdio>
using namespace std;
int n, m;
int aa[1000], cc[1000];
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; ++i) {scanf("%d", cc+i);}
  for(i=0; i<m; ++i) {scanf("%d", aa+i);}

  i=0, j=0;
  while(i<n && j<m) {
    if(cc[i] <= aa[j]) {
      ++j;
    }
    ++i;
  }
  printf("%d", j);
}
