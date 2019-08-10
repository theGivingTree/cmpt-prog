#include <cstdio>
using namespace std;
int N;
bool aa[100000];
int main() {
  int i, a;
  int rem, ans;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    scanf("%d", &a);
    aa[--a] = true;
  }
  rem = ans = 0;
  for(i=0; i<2*N; ++i) {
    if(aa[i]) {
      ++rem;
    }
    else if(rem > 0) {
      --rem;
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
