#include <cstdio>
using namespace std;
int n;
int main() {
  int i, j, s=0, t=0;
  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    s+=a;
  }
  for(i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    t+=a;
  }
  if(s>=t) puts("Yes");
  else puts("No");
  return 0;
}
