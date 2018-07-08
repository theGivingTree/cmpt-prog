#include <cstdio>
#include <cmath>
using namespace std;
int T;
int h, c, a[200], cc[200][200];
float d[200][200];
int main() {
  scanf("%d", &T);
  while(T--) {
    int i, j, k;
    scanf("%d %d", &h, &c);

    for(i=0; i<h; ++i) scanf("%d", a+i);
    for(i=0; i<h-1; ++i) {
      cc[i][i+1] = 0;
      for(j=i+2; j<h; ++j) {
        int sum=0, d;
        for(k=i+1; k<=j; ++k) {
          d=(j-i)*(a[k]-a[i])-(a[j]-a[i])*(k-i);
          if(d<0) d=-d;
          sum += d;
        }
        cc[i][j] = sum; // real value : sum/(j-i)
      }
    }

    for(i=1; i<h; ++i) {
      d[i][0] = 1.0f*cc[0][i]/i;
      d[i][i-1] = .0f;

      int JS = 1;
      int JC = i-2;
      if(JS < c-(h-i+1)) JS = c-(h-i+1);
      if(JC > c-2) JC = c-2;

      for(j=JS; j<=JC; ++j) {
        // calculate d[i][j]
        float min=INFINITY, v;
        for(k=j; k<i; ++k) {
          v = d[k][j-1] + 1.0f*cc[k][i]/(i-k);
          if(min > v) min = v;
        }
        d[i][j] = min;
      }
    }

    printf("%.4f\n", d[h-1][c-2]/h);
  }
  return 0;
}
