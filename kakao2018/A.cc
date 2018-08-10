#include <cstdio>
int T;
int get1(int x) {
  if(x==0) return 0;
  if(x<=1) return 500;
  x-=1;
  if(x<=2) return 300;
  x-=2;
  if(x<=3) return 200;
  x-=3;
  if(x<=4) return 50;
  x-=4;
  if(x<=5) return 30;
  x-=5;
  if(x<=6) return 10;
  return 0;
}
int get2(int x) {
  if(x==0) return 0;
  if(x<=1) return 512;
  x-=1;
  if(x<=2) return 256;
  x-=2;
  if(x<=4) return 128;
  x-=4;
  if(x<=8) return 64;
  x-=8;
  if(x<=16) return 32;
  return 0;
}
int main() {
  scanf("%d", &T);
  while(T--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (get1(a) + get2(b))*10000);
  }
  return 0;
}
