#include <cstdio>
using namespace std;
long long solve(int n, int cc[]) {
  int i;
  bool isUni = true;
  for(i=0; i<n; ++i) {
    if(cc[i] == 0) isUni = false;
  }
  if(isUni) return 0;

  int inc = 0;
  int start = 0;
  for(i=0; i<n; ++i) {
    if(inc == 0 && cc[i] == 0) ++start;
    else inc += cc[i]-1;
  }

  long long ans = 0;
  inc = start;
  for(i=0; i<n; ++i) {
    int c = cc[i];
    long long k = inc + c;
    inc += cc[i] - 1;
    if(cc[i] == 0) continue;

    ans += (k-1)*k*(2*k-1)/6 - (k-c-1)*(k-c)*(2*k-2*c-1)/6;
  }
  return ans;
}
int main() {
  int i, n, cc[100000];
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    cc[i] = a;
  }

  printf("%lld", solve(n, cc));
  return 0;
}
