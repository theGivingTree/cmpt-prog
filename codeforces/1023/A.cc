#include <cstdio>
#include <cstring>
using namespace std;
int const NMAX = 200000;
char s[NMAX+1], t[NMAX+1];
int main() {
  int i, j;
  int sl, tl;
  scanf("%d%d", &sl, &tl);
  scanf("%s%s", s, t);
  bool result = true;
  i=0;
  while((i<sl || i<tl) && s[i]!='*') {
    if(s[i] != t[i]) {
      result = false;
      break;
    }
    ++i;
  }

  if(!result) {
    puts("NO");
    return 0;
  }
  else if(s[i] != '*') {
    puts("YES");
    return 0;
  }

  int wildpos = i;
  i=sl-1, j=tl-1;
  while(i > wildpos && j >= wildpos) {
    if(s[i] != t[j]) {
      result = false;
      break;
    }
    --i, --j;
  }

  if(!result || i > wildpos) {
    puts("NO");
    return 0;
  }
  else {
    puts("YES");
    return 0;
  }
  return 0;
}
