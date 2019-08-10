#include <cstdio>
#include <vector>
using namespace std;
int qq;
int prdc[4];
int main() {
  scanf("%d", &qq);
  while(qq--) {
    int i, n;
    scanf("%d",&n);
    prdc[0] = 100000;
    prdc[1] = -100000;
    prdc[2] = -100000;
    prdc[3] = 100000;
    for(i=0; i<n; ++i) {
      int x, y, f0, f1, f2, f3;
      scanf("%d%d%d%d%d%d",&x,&y,&f0,&f1,&f2,&f3);
      bool f;
      f = !f0 && !f2;
      if(f0 && !f2 || f) {
        if(prdc[0] > x) {
          prdc[0] = x;
        }
      }
      if(!f0 && f2 || f) {
        if(prdc[2] < x) {
          prdc[2] = x;
        }
      }
      f = !f1 && !f3;
      if(f1 && !f3 || f) {
        if(prdc[1] < y) {
          prdc[1] = y;
        }
      }
      if(!f1 && f3 || f) {
        if(prdc[3] > y) {
          prdc[3] = y;
        }
      }
    }

    if(prdc[2] <= prdc[0] && prdc[1] <= prdc[3]) {
      printf("1 %d %d\n", prdc[2], prdc[1]);
    }
    else puts("0");
  }
  return 0;
}
