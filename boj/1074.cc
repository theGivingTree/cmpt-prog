#include <cstdio>
using namespace std;
int N, r, c, ans, k;
int main() {
  scanf("%d%d%d", &N, &r, &c);
  k=1;
  for(;N--; r>>=1, c>>=1, k<<=2) ans+=k*((r%2<<1)+c%2);
  printf("%d", ans);
  return 0;
}
