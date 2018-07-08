#include <cstdio>
#include <cstring>
using namespace std;
int T, test_case;
char a[30001], ans[30001];
int al;
int main() {
  int i, j;
  scanf("%d", &T);
  for(test_case=1; test_case<=T; ++test_case) {
    scanf(" %s", a);
    printf("#%d ", test_case);
    i = 0;
    j = strlen(a) - 1;
    al = 0;
    while(i<j) {
      if(a[i]<a[j]) ans[al++]=a[i++];
      else if(a[i]>a[j]) ans[al++]=a[j--];
      else {
        ans[al++]=a[i];
        int ix=i+1, jx=j-1;
        while(ix<jx && a[ix]==a[jx]) ++ix, --jx;
        if(a[ix]<a[jx]) ++i;
        else --j;
      }
    }
    if(i==j) ans[al++]=a[i];
    ans[al]=0;
    puts(ans);
  }
  return 0;
}
