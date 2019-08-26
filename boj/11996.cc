#include <cstdio>
using namespace std;
int solve(int n, int cc[]) {
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

  int ans = 0;
  inc = start;
  for(i=0; i<n; ++i) {
    int c = cc[i];
    int k = inc + c;
    inc += cc[i] - 1;
    if(cc[i] == 0) continue;

    ans += (k-1)*k*(2*k-1)/6 - (k-c-1)*(k-c)*(2*k-2*c-1)/6;
  }
  return ans;
}
int main() {
  int i, n, cc[1000];
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    cc[i] = a;
  }

  printf("%d", solve(n, cc));
  return 0;
}
