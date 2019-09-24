#include <cstdio>
#include <algorithm>
using namespace std;
int N, Q;
int hb[100000];
int main() {
  int i;
  scanf("%d%d",&N,&Q);
  for(i=0; i<N; ++i) {
    int a;
    scanf("%d", &a);
    hb[i] = a;
  }
  sort(hb, hb+N);
  for(i=0; i<Q; ++i) {
    int a,b;
    int *pa,*pb;
    scanf("%d%d",&a,&b);
    --a;
    pa = upper_bound(hb, hb+N, a);
    pb = upper_bound(pa, hb+N, b);
    printf("%ld\n", pb-pa);
  }
  return 0;
}
