#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N_MAX 500000
int T, test_case;
int N, M, dd[N_MAX], LL[N_MAX+1], RR[N_MAX+1];
int ll[N_MAX+2], rr[N_MAX+2];
int main() {
  int i, j;
  memset(dd, 0x77, N_MAX*sizeof(int));
  for(i=0; i<=N_MAX; ++i) LL[i]=i,RR[i]=i+1;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N >> M;
    memcpy(ll+1, LL, (N+1)*sizeof(int));
    memcpy(rr, RR, (N+1)*sizeof(int));
    for(i=0; i<M; ++i) {
      char a;
      int x, y;
      cin >> a >> x >> y;
      int l=ll[x], r=rr[x];
      rr[l] = r;
      ll[r] = l;

      int nl, nr;
      if(a=='A') {
        nl=ll[y];
        nr=y;
      }
      else {
        nl=y;
        nr=rr[y];
      }
      ll[x]=nl;
      rr[x]=nr;
      rr[nl]=x;
      ll[nr]=x;
    }
    memcpy(ll, dd, N*sizeof(int));
    for(j=rr[0]; j!=N+1; j=rr[j]) {
      int lo=0, hi=N, mi;
      while(lo<hi) {
        mi=(lo+hi)/2;
        if(ll[mi] > j) hi=mi;
        else lo=mi+1;
      }
      ll[lo]=j;
    }
    for(i=0; ll[i]!=0x77777777; ++i);
    cout << '#' << test_case << ' ' << N-i << endl;
  }
  return 0;
}
