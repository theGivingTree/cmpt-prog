#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int ss[5000], ee[5000], cc[5000];
int crds[10000], sz_crds;
vector<vector<int>> ssi, eei;
int findIdx(int a) {
  return lower_bound(crds, crds+sz_crds, a) - crds;
}
int refine() {
  int totdup = 0;
  for(i=1; i<2*N; ++i) {
    if(crds[i-1] == crds[i]) {
      ++totdup;
    }
    else {
      crds[i-totdup] = crds[i];
    }
  }
  return 2*N - totdup;
}

int (*dp)[5000];
int main() {
  int i, j;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    int d;
    scanf("%d %d %d", &ss[i], &d, &cc[i]);
    ee[i] = ss[i]+d;
    crds[i] = ss[i];
    crds[N+i] = ee[i];
  }
  sort(crds, crds+2*N);
  sz_crds = refine();
  ssi.resize(sz_crds+1);
  eei.resize(sz_crds+1);

  int idxMax = 0;
  for(i=0; i<N; ++i) {
    int start, end;
    start = findIdx(ss[i]) + 1;
    end = findIdx(ee[i]) + 1;
    ss[i] = start; ssi[start].push_back(i);
    ee[i] = end; eei[end].push_back(i);
    if(idxMax < ee[i]) idxMax = ee[i];
  }
  dp = (int (*)[5000])new int[(idxMax+1)*5000];

  for(j=1; j<=idxMax; ++j) {
    for(i=0; i<N; ++i) {
    }
  }

  delete[] dp;
  return 0;
}
