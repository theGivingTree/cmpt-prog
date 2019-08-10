#include <cstdio>
using namespace std;
int TC;
int n, k;
int ans[200000];
int main() {
  scanf("%d", &TC);
  while(TC--) {
    scanf("%d%d",&n,&k);

    int i;
    int c = 0;
    for(i=0; i<n && c<k-1; ++i) {
      int a;
      scanf("%d",&a);
      if(a&1) {
        ans[c++] = i+1;
      }
    }
    bool odd = false;
    for(; i<n; ++i) {
      int a;
      scanf("%d",&a);
      if(a&1) odd = !odd;
    }
    if(odd) {
      puts("YES");
      ans[k-1] = n;
      for(i=0; i<k; ++i) {
        printf("%d ", ans[i]);
      }
      putchar('\n');
    }
    else {
      puts("NO");
    }
  }
  return 0;
}
