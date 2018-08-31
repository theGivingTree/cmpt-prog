#include <cstdio>
using namespace std;
int n, m;
int main() {
  int i=0;
  scanf("%d%d", &n, &m);
  int xsum=0;
  long long dsum=0;
  int invcnt = 0;
  for(i=0; i<m; ++i) {
    int x, d;
    scanf("%d%d", &x,&d);
    xsum+=x;
    if(d<0) {
      if(n&1) {
        dsum += n*d;
        invcnt+=-d;
      }
      else {
        dsum += n*d;
      }
    }
    else {
      dsum += d*(2*n-2);
    }
  }
  printf("%.6lf", xsum + dsum/4.0 + invcnt/(4.0*n));
}
