#include <cstdio>
using namespace std;
char s[100001];
int main() {
  int i;
  scanf("%s",s);
  int ans=1, loca=1;
  bool first = false;
  int f1=1, f2=1;
  for(i=1; s[i]; ++i) {
    if(s[i] != s[i-1]) ++loca;
    else {
      if(ans < loca) ans = loca;
      if(!first) {
        f1 = loca;
        first = true;
      }
      loca = 1;
    }
  }
  if(ans < loca) ans = loca;
  if(!first) f1 = loca;
  f2 = loca;
  if(s[0] != s[i-1]) {
    if(ans < f1+f2) ans = f1+f2;
  }
  if(ans > i) ans = i;
  printf("%d", ans);
  return 0;
}
