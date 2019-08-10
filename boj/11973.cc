#include <cstdio>
#include <algorithm>
using namespace std;
int N, K;
int hb[50000];
int main() {
  int i;
  scanf("%d%d",&N,&K);
  for(i=0; i<N; ++i) {
    scanf("%d", &hb[i]);
  }
  sort(hb, hb+N);
  int radL = 0, radR = (hb[N-1]-hb[0]+(2*K-1))/(2*K);
  while(radL<radR) {
    int rad = (radL+radR)/2;
    int s = 0, k = 0;
    while(k<K && s<N) {
      int ss = hb[s];
      while(s<N && hb[s] <= ss+rad*2) ++s;
      ++k;
    }
    if(s<N && k>=K) {
      radL = rad + 1;
    }
    else {
      radR = rad;
    }
  }
  printf("%d", radR);
  return 0;
}
