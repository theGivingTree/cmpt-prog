#include <cstdio>
using namespace std;
int L,P,V;
int main() {
  int t;
  for(t=1; scanf("%d%d%d", &L, &P, &V), L; ++t) printf("Case %d: %d\n", t, V/P*L+(V%P<L?V%P:L));
  return 0;
}
