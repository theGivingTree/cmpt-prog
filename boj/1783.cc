#include <stdio.h>
long long N, M, ans=1;
int main() {
  scanf("%lld %lld", &N, &M);
  if(N==2 && (ans=(M+1)/2)) {if(ans>4) ans=4;}
  else if(N>2 && (ans=M-2)|1) {if(M<6 && (ans=4)) if(M<4) ans=M;}
  printf("%lld", ans);
}
