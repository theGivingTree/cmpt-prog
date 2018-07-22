#include <iostream>
#include <algorithm>
using namespace std;
int T, test_case;
int N, M, H[222222], MIN_HEIGHT, MAX_HEIGHT;
int downbound[222222], upbound[222222];
void genInput() {
  int i, j;
  int w, x, y, z;
  cin >> H[0] >> H[1] >> w >> x >> y >> z;
  H[0]*=2;
  H[1]*=2;
  y*=2;
  z*=2;
  MIN_HEIGHT = H[0], MAX_HEIGHT = H[1];
  if(H[0] > H[1]) {
    swap(MIN_HEIGHT, MAX_HEIGHT);
  }
  for(i=2; i<N; ++i) {
    H[i] = (1LL*w*H[i-2] + 1LL*x*H[i-1] + y) % z;
    MIN_HEIGHT = min(MIN_HEIGHT, H[i]);
    MAX_HEIGHT = max(MAX_HEIGHT, H[i]);
  }
}
int main() {
  cout << fixed;
  cout.precision(6);
  int i, j;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N >> M;
    genInput();
    for(i=0; i<N-1; ++i) {
      downbound[i] = 2000000;
      upbound[i] = 2000000;
    }
    for(i=0; i<M; ++i) {
      int a, b, u, d;
      cin >> a >> b >> u >> d;
      --a, --b, u*=2, d*=2;
      if(a>b) {
        swap(a, b);
        swap(u, d);
      }
      for(j=a; j<b; ++j) {
        downbound[j] = min(downbound[j], d);
        upbound[j] = min(upbound[j], u);
      }
    }

    int lo=0, hi=(MAX_HEIGHT-MIN_HEIGHT)/2, m, ans=-1;
    while(lo<=hi) {
      m = (lo+hi)/2;

      int minH, maxH;
      minH = H[0] - m, maxH = H[0] + m;
      if(minH < 0) minH = 0;
      for(i=1; i<N; ++i) {
        int minHi, maxHi, minx, maxx;
        minHi = H[i] - m, maxHi = H[i] + m;
        if(minHi < 0) minHi = 0;

        minx = minH - downbound[i-1], maxx = maxH + upbound[i-1];
        if(minx < 0) minx = 0;

        minH = max(minHi, minx);
        maxH = min(maxHi, maxx);

        if(minH > maxH) break;
      }

      if(i==N) {
        // success
        ans = m;
        hi = m-1;
      }
      else {
        // fail
        lo = m+1;
      }
    }

    cout << "Case #" << test_case << ": " << ans/2.0 << '\n';
  }
  return 0;
}
