#include <cstdio>
using namespace std;
int N, tr[1<<20];
int lvl[300001], scs[300001];
int main() {
  int i, j, k, Z;
  scanf("%d", &N);
  for(Z=1; Z<N; Z*=2);

  long long C=0;
  lvl[0] = -1;
  for(k=0; k<N; ++k) {
    int X, start;
    scanf("%d", &X);
    start = 0;
    for(j=i=Z+X-1; i; j=i, i/=2) {
      ++tr[i];
      if(start==0 && tr[i]-tr[j] > 0 && j%2==1) {
        start = j-1;
      }
    }
    if(start == 0) {
      j = scs[0];
      lvl[X] = lvl[j]+1;
      scs[X] = j;
      scs[0] = X;
    }
    else {
      i=start;
      while(i<Z) {
        i*=2;
        if(tr[i+1]>0) ++i;
      }
      int pre = i-Z+1;
      if(lvl[pre] < lvl[scs[pre]]) {
        lvl[X] = lvl[scs[pre]] + 1;
        scs[X] = scs[pre];
        scs[pre] = X;
      }
      else {
        lvl[X] = lvl[pre] + 1;
        scs[X] = scs[pre];
        scs[pre] = X;
      }
    }
    C += lvl[X];
    printf("%lld\n", C);
  }
  return 0;
}
