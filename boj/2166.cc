#include <cstdio>
#include <cmath>
using namespace std;
int N;
long long area;
int main() {
  int i, j;
  int x0, y0;
  int prx, pry;
  scanf("%d", &N);
  scanf("%d %d", &x0, &y0);
  prx = x0;
  pry = y0;
  for(i=1; i<N; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    area += 1LL*(prx+x)*(pry-y);
    prx = x, pry = y;
  }
    area += 1LL*(prx+x0)*(pry-y0);
  printf("%.1lf\n", abs(area/2.0));
}
