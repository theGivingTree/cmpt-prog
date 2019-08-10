#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int N, NI, NJ;
  scanf("%d", &N);
  vector<int> upper_row(N), lower_row(N);
  vector<vector<int>> d1(N+1, vector<int>(N+1, INT_MIN)), d2(N+1, vector<int>(N+1));
  NI = NJ = 0;
  for(int i=0; i<N; ++i) {
    int v; scanf("%d", &v); if(v!=0) upper_row[NI++] = v;
  }
  for(int i=0; i<N; ++i) {
    int v; scanf("%d", &v); if(v!=0) lower_row[NJ++] = v;
  }
  d1[0][0] = 0;
  int is, js, _is, _js, ie, je;
  for(int k=1; k<=N; ++k) {
    _is = is = NI-N+k;
    _js = js = NJ-N+k;
    if(is < 1) is = 0, _is = 1;
    if(js < 1) js = 0, _js = 1;
    ie = NI;
    je = NJ;
    if(ie > k) ie = k;
    if(je > k) je = k;
    int bis=is-1, bie=ie+1, bjs=js-1, bje=je+1;
    bool fbis, fbie, fbjs, fbje;
    fbis=fbie=fbjs=fbje=true;
    if(bis < 0) bis = 0, fbis=false;
    if(bjs < 0) bjs = 0, fbjs=false;
    if(bie > NI) bie = NI, fbie=false;
    if(bje > NJ) bje = NJ, fbje=false;
    if(fbis) for(int j=bjs; j<=bje; ++j) d2[bis][j] = INT_MIN;
    if(fbjs) for(int i=bis; i<=bie; ++i) d2[i][bjs] = INT_MIN;
    if(fbie) for(int j=bjs; j<=bje; ++j) d2[bie][j] = INT_MIN;
    if(fbje) for(int i=bis; i<=bie; ++i) d2[i][bje] = INT_MIN;

    if(is == 0) for(int j=js; j<=je; ++j) d2[0][j] = 0;
    if(js == 0) for(int i=is; i<=ie; ++i) d2[i][0] = 0;

    for(int i=_is; i<=ie; ++i) {
      for(int j=_js; j<=je; ++j) {
        int a, p;
        p = d1[i][j];
        if(p < (a=d1[i-1][j])) p = a;
        if(p < (a=d1[i][j-1])) p = a;
        if(p < (a=d1[i-1][j-1]+upper_row[i-1]*lower_row[j-1])) p = a;
        d2[i][j] = p;
      }
    }
    d1.swap(d2);
  }
  printf("%d", d1[NI][NJ]);
  return 0;
}
