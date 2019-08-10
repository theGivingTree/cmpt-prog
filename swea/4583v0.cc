#include <iostream>
#include <cstring>
using namespace std;
// modular exponentiation!!

int T, test_case;
// M, K, base exchange, net permutation, rules
int M, bl[7], r[20][2], bb[7], ans[7];
long long K, rk, qk;

void sqperm(int bl[]) {
  int i;
  for(i=0; i<7; ++i) {
    bb[i] = bl[bl[i]];
  }
  memcpy(bl, bb, 7*sizeof(int));
}
int main() {
  int i;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> M >> K;
    for(i=0; i<7; ++i) ans[i] = bl[i] = i;
    for(i=0; i<M; ++i) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      r[i][0] = a;
      r[i][1] = b;
      swap(bl[a], bl[b]);
    }
    rk = K%M;
    qk = K/M;
    for(; qk; qk>>=1) {
      if(qk&1) {
        for(i=0; i<7; ++i) {
          bb[i] = ans[bl[i]];
        }
        memcpy(ans, bb, 7*sizeof(int));
      }
      sqperm(bl);
    }
    for(i=0; i<rk; ++i) {
      int a = r[i][0], b = r[i][1];
      swap(ans[a], ans[b]);
    }

    cout << '#' << test_case << ' ';
    for(i=0; i<7; ++i) cout << ans[i];
    cout << endl;
  }
  return 0;
}
