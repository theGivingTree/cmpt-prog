#include <cstdio>
#include <algorithm>
using namespace std;
int N, a[1000];
int main() {
  int i, ans=0;
  scanf("%d", &N);
  for(i=0; i<N; ++i) scanf("%d", a+i);
  sort(a, a+N);
  for(i=0; i<N; ++i) ans+=a[i]*(N-i);
  printf("%d", ans);
  return 0;
}
