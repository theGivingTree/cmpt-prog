#include <cstdio>
using namespace std;
int n;
char s[101];
int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int i, j;
    scanf("%d %s", &n, s);
    bool flag = false;
    for(i=0, j=n-1; i<j; ++i, --j) {
      if(s[i] == s[j]) continue;
      int a1, a2, b1, b2;
      a1 = s[i]-1;
      a2 = s[i]+1;
      b1 = s[j]-1;
      b2 = s[j]+1;
      if(a1 == b1 || a1 == b2 || a2 == b1 || a2 == b2) continue;
      flag = true;
      puts("NO");
      break;
    }
    if(flag) continue;
    puts("YES");
  }
  return 0;
}
