#include <iostream>
#include <iomanip>
#include <cstring>
#include <cfloat>
#include <cmath>
#define sq(x) (LL(x)*(x))
using namespace std;
using LL = long long;

struct Sen {
  // wall -> r=0
  int x, y, r;
};
int w, n;
Sen senList[1002];
double ddd[1002];
int trace[1002];
bool visit[1002];

double eucDist(Sen const& q1, Sen const& q2) {
  int dx = q1.x - q2.x, dy = q1.y - q2.y;
  double ptp;
  if(q1.r == 0 || q2.r == 0) {
    ptp = dx > 0 ? dx : -dx;
  }
  else ptp = sqrt(sq(dx) + sq(dy));
  return ptp - (q1.r + q2.r);
};

int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cout << fixed;
  cout << setprecision(6);
  int T;
  cin >> T;
  while(T--) {
    int i, j;
    cin >> w >> n;
    senList[0] = {0, 0, 0};
    for(i=1; i<=n; ++i) {
      int x, y, r;
      cin >> x >> y >> r;
      senList[i] = {x, y, r};
      ddd[i] = DBL_MAX;
    }
    senList[n+1] = {w, 0, 0};
    ddd[n+1] = DBL_MAX;
    memset(visit, 0, sizeof(bool)*(n+2));
    
    ddd[0] = 0;
    for(i=0; i<=n+1; ++i) {
      int nxt=-1; double md=DBL_MAX;
      for(j=0; j<=n+1; ++j) {
        if(!visit[j] && md > ddd[j]) {
          md = ddd[j]; nxt = j;
        }
      }
      visit[nxt] = true;
      for(j=0; j<=n+1; ++j) {
        if(visit[j]) continue;
        auto cost = eucDist(senList[nxt], senList[j]);
        if(cost < 0) cost = 0;
        if(ddd[j] > cost) {
          ddd[j] = cost;
          trace[j] = nxt;
        }
      }
    }

    int r = n+1;
    double max = 0.0;
    do {
      if(max < ddd[r]) max = ddd[r];
      r=trace[r];
    } while(r!=0);

    cout << max/2 << '\n';
  }
  return 0;
}
