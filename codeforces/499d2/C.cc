#include <cstdio>
using namespace std;
int N, A[1111], B[1111];
double M;
bool check(double fuel) {
  int i, j;
  double req;
  for(i=0; i<N; ++i) {
    // take-off
    req = (M + fuel)/A[i];
    if(req > fuel) break;
    fuel -= req;
    // landing
    req = (M + fuel)/B[i+1];
    if(req > fuel) break;
    fuel -= req;
  }

  return i==N;
}
int main() {
  int i, j;
  scanf("%d %lf", &N, &M);
  for(i=0; i<N; ++i) {
    scanf("%d", A+i); //lift
  }
  A[N]=A[0];
  for(i=0; i<N; ++i) {
    scanf("%d", B+i); //land
  }
  B[N]=B[0];

  if(!check(1e9+1e-6)) {
    puts("-1");
    return 0;
  }

  double lo=.0, hi=1e9, mi;
  while(hi-lo>1e-6) {
    mi = (lo+hi)/2;
    if(check(mi)) hi = mi;
    else lo = mi;
  }
  printf("%.10lf", (lo+hi)/2);
  return 0;
}
