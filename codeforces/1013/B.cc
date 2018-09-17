#include <cstdio>
using namespace std;
int n, x;
bool aa[100001];
bool bb[100001];
int main() {
  int i, j;
  scanf("%d %d", &n, &x);
  for(i=0; i<n; ++i) {
    int v;
    scanf("%d", &v);
    if(aa[v]) {
      puts("0");
      return 0;
    }
    aa[v] = true;
  }
  int ans=-1;
  for(i=1; i<=100000; ++i) {
    if(!aa[i]) continue;
    if(i == (i&x)) continue;
    if(aa[i&x]) {
      puts("1");
      return 0;
    }
    if(bb[i&x]) {
      ans = 2;
    }
    bb[i&x] = true;
  }
  printf("%d", ans);
}
