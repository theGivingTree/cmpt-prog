#include <cstdio>
using namespace std;
int n;
int main() {
  int i;
  scanf("%d", &n);
  int maxc = 0;
  for(i=0; i<n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(maxc < x+y) maxc = x+y;
  }
  printf("%d", maxc);
  return 0;
}
