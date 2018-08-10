#include <cstdio>
using namespace std;
int main() {
  int a, b=0, c=0;
  scanf("%d", &a);
  c+=a;
  if(a<0) b=1;
  while(scanf("%d", &a)==1) {
    if(b) c+=a<0?a:-a;
    else {
      c+=a;
      if(a<0) b=1;
    }
  }
  printf("%d", c);
  return 0;
}
