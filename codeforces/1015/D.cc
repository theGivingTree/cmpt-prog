#include <cstdio>
using namespace std;
int n, k;
long long s;
int main() {
  int i, j;
  scanf("%d %d %lld", &n, &k, &s);
  if(s<k || 1LL*k*(n-1)<s) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int p=1;
  while(s-(n-1)>=k-1 && k>0) {
    if(p==1) {
      printf("%d ", p=n);
    }
    else {
      printf("%d ", p=1);
    }
    s-=n-1, --k;
  }
  if(k==0) return 0;
  bool flag = false;
  for(i=0; i<k-1; ++i) {
    flag = !flag;
    printf("%d ", p+(p==1?flag:-flag));
  }
  printf("%lld ", p+(p==1?(flag+s-k+1):-(flag+s-k+1)));
  return 0;
}
