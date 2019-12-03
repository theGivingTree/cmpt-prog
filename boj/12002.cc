#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int i, j, k;
  int N;
  int cx[50000], cy[50000];
  int iix[50000], iiy[50000];
  bool ff[50000];
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    scanf("%d%d", cx+i, cy+i);
    iix[i] = iiy[i] = i;
    ff[i] = false;
  }
  sort(iix, iix+N, [cx=cx](int a, int b) {
    return cx[a] < cx[b];
  });
  sort(iiy, iiy+N, [cy=cy](int a, int b) {
    return cy[a] < cy[b];
  });
  vector<int> rng; rng.reserve(12);
  for(i=0; i<3; ++i) {
    if(find(rng.begin(), rng.end(), iix[i]) == rng.end()) rng.push_back(iix[i]);
    if(find(rng.begin(), rng.end(), iix[N-1-i]) == rng.end()) rng.push_back(iix[N-1-i]);
    if(find(rng.begin(), rng.end(), iiy[i]) == rng.end()) rng.push_back(iiy[i]);
    if(find(rng.begin(), rng.end(), iiy[N-1-i]) == rng.end()) rng.push_back(iiy[N-1-i]);
  }
  int L = rng.size();
  int ans = 0x7fFFffFF;
  for(i=0; i<L-2; ++i) for(j=i+1; j<L-1; ++j) for(k=j+1; k<L; ++k) {
    int e;
    ff[rng[i]]=ff[rng[j]]=ff[rng[k]] = true;
    int xa, xb, ya, yb;
    for(e=0; ff[iix[e]]; ++e); xa = cx[iix[e]];
    for(e=N-1; ff[iix[e]]; --e); xb = cx[iix[e]];
    for(e=0; ff[iiy[e]]; ++e); ya = cy[iiy[e]];
    for(e=N-1; ff[iiy[e]]; --e); yb = cy[iiy[e]];
    int val = (xb-xa)*(yb-ya);
    if(ans > val) ans = val;
    ff[rng[i]]=ff[rng[j]]=ff[rng[k]] = false;
  }
  printf("%d", ans);
  return 0;
}
