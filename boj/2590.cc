#include <cstdio>
using namespace std;
int a,b,c,d,e,ans;
int kk(int th, int aa) {
  int k=b;
  if(k>th) {
    k=th;
    b-=th;
  } else b=0;
  a=a+k*4-aa;
  if(a<0) a=0;
  return 1+(a+b*4+35)/36;
}
int main() {
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&ans);
  ans+=e;
  a-=e*11;
  if(a<0) a=0;
  ans+=d;
  b-=d*5;
  if(b<0) {
    a-=-b*4;
    if(a<0) a=0;
    b=0;
  }
  ans+=c/4;
  c%=4;
  ans+=b/9;
  b%=9;
  if(c==0) {
    ans+=(a+b*4+35)/36;
  }
  else if(c==1) {
    ans+=kk(5, 27);
  }
  else if(c==2) {
    ans+=kk(3, 18);
  }
  else {
    ans+=kk(1, 9);
  }
  printf("%d", ans);
  return 0;
}
