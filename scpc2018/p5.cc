#include <iostream>

using namespace std;
using LL = long long;

int N, M, L;
struct vec2 {
  int x; LL y; 
} msegs[200001];

int main() {
  int T, test_case;
  cin >> T;
  for(test_case = 0; test_case  < T; test_case++) {

    cin >> N >> M >> L;

    N *= 2;
    LL lo=0, hi=0, H;
    for(int i=0; i<M+1; ++i) {
      int x;
      LL y;
      cin >> x >> y;
      msegs[i].x = x*2, msegs[i].y = y*2;
      if(hi < msegs[i].y) hi = msegs[i].y;
    }
    LL maxH = hi++;

    while(lo<hi) {
      H = (lo+hi)/2;

      LL last = 0LL;
      int cnt;
      int i=0, n_last;
      for(cnt=0; cnt<L && last<N; ++cnt) {
        n_last = 0;
        LL xh=0;
        bool dup = false;
        for(; i<M; ++i) {
          int x1 = msegs[i].x, x2 = msegs[i+1].x;
          LL y1 = msegs[i].y, y2 = msegs[i+1].y;
          if(y1 < y2) {
            if(y2 <= H) {
              xh = x2;
              dup = true;
            }
            else {
              xh = x1+(H-y1);
              if(xh < x1) continue;
              if(xh == x1 && dup) {
                dup = false;
                continue;
              }
            }
          }
          else {
            if(y1 <= H) {
              if(dup) {
                dup = false;
                continue;
              }
              xh = x1;
            }
            else {
              xh = x1-(H-y1);
              if(xh > x2) continue;
              if(xh == x2) {
                dup = true;
              }
            }
          }
          if(xh - H > last) break;
          n_last = xh + H;
        }

        last = n_last;
        if(last == 0) break;
      }

      if(last<N) {
        lo = H+1;
      }
      else {
        hi = H;
      }
    }

    cout << "Case #" << test_case+1 << endl;
    if(hi > maxH) {
      cout << -1 << endl;
    }
    else if(hi%2) {
      cout << hi << " " << 2 << endl;
    }
    else {
      cout << hi/2 << " " << 1 << endl;
    }
  }

  return 0;
}
