#include <cstdio>
using namespace std;
int main() {
  int G, i, cnt=0;
  scanf("%d", &G);
  if(G<=2) {puts("-1");return 0;}
  for(i=1; i*i<=G; ++i);
  for(--i; i>0; --i) {
    if(G%i==0 && G/i!=i && (G/i+i&1)==0) cnt++, printf("%d\n", (G/i+i)/2);
  }
  if(!cnt) puts("-1");
  return 0;
}
