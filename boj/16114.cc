#include <cstdio>
#include <cstdlib>
using namespace std;
int x, n;
int main() {
  scanf("%d%d",&x,&n);
  if(n==1) {
    x=-x;
    n=0;
  }
  if(n==0) {
    if(0<x) puts("INFINITE");
    else puts("0");
    exit(0);
  }
  if(n&1) {
    puts("ERROR");
    exit(0);
  }
  if(x<=0) {
    puts("0");
    exit(0);
  }
  n/=2;
  printf("%d", (x-1)/n);
  return 0;
}
