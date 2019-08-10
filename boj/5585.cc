#include <cstdio>
using namespace std;
int main() {
  int i, a, b=0, c[]={500,100,50,10,5,1};
  scanf("%d", &a), a=1000-a;
  for(i=0; i<6; ++i) b+=a/c[i], a%=c[i];
  printf("%d", b);
  return 0;
}
