#include <cstdio>
#include <algorithm>
using namespace std;
bool f; int a, b;
char bb[100001];
int main() {
  int i;
  scanf("%s", bb);
  for(i=0;bb[i];++i) { a=bb[i]-'0';b+=a;f=!a||f; }
  if(f&&b%3==0) {
    sort(bb, bb+i);
    while(i--) putchar(bb[i]);
  }
  else puts("-1");
  return 0;
}
