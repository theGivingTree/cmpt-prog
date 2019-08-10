#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
constexpr int N_MAX = 100000;
int n, an[N_MAX];
int ans_val = 0x7fFFffFF;
int Ax, Bx;
void update(int A, int B) {
  int z = abs(A+B);
  if(ans_val > z) {
    ans_val = z;
    Ax=A, Bx=B;
  }
}
void solve();
int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", &an[i]);
  }
  sort(an, an+n);
  solve();
  printf("%d %d", Ax, Bx);
  sort(an, an+n);
  return 0;
}
void solve() {
  int i;
  int ia=0, ib=n-1;
  while(ia<ib) {
    int A = an[ia], B = an[ib];
    update(A, B);
    if(A+B==0) break;
    if(A+B>0) --ib;
    else ++ia;
  }
}
