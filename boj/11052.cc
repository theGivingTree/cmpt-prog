#include <cstdio>
using namespace std;
int N, d[1001];
int main() {
  int i, j;
  scanf("%d", &N);
  for(i=1; i<=N; ++i) {
    int p;
    scanf("%d", &p);
    for(j=0; j<=N-i; ++j) {
      int val = d[j] + p;
      if(d[j+i] < val) d[j+i] = val;
    }
  }
  printf("%d", d[N]);
  return 0;
}
