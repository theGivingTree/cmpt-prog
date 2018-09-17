#include <cstdio>
int n, m, aa[300000], bb[300000];
using namespace std;
using LL = long long;
int main() {
  int i, j;
  scanf("%d",&n);
  for(i=0; i<n; ++i) scanf("%d", aa+i);
  scanf("%d",&m);
  for(j=0; j<m; ++j) scanf("%d", bb+j);
  i=j=0;
  LL ans = 0;
  LL as=0, bs=0;
  while(i<n && j<m) {
    as=aa[i++], bs=bb[j++];
    while(as!=bs && i<n && j<m) {
      while(as<bs && i<n) as += aa[i++];
      while(as>bs && j<m) bs += bb[j++];
    }
    while(as<bs && i<n) as += aa[i++];
    while(as>bs && j<m) bs += bb[j++];
    if(as!=bs) break;
    ++ans;
  }
  if(i==n && j==m && as == bs) printf("%lld\n", ans);
  else puts("-1");
  return 0;
}
