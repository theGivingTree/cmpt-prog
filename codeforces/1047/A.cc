#include <cstdio>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if(n%3==0) { printf("%d %d %d", 1, 1, n-2); }
  else if((n+2)%3==0) { printf("%d %d %d", 1, 1, n-2); }
  else { printf("%d %d %d", 1, 2, n-3); }
  return 0;
}
