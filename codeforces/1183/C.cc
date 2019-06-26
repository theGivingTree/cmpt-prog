#include <cstdio>
using namespace std;
int query() {
  int k,n,a,b;
  scanf("%d%d%d%d",&k,&n,&a,&b);
  int ret = ((k - 1LL*b*n) + (a-b-1)) / (a-b) - 1;
  if(ret > n) return n;
  if(ret < 0) return -1;
  return ret;
}
int main() {
  int a;
  scanf("%d", &a);
  while(a--) printf("%d\n", query());
  return 0;
}

