#include <iostream>
#include <cstring>
using namespace std;
// modular exponentiation!!

int T, test_case;
// M, K, base exchange, net permutation, rules
int i, j, M, bl[7], r[20][2], bb[7], ans[7];
long long K, rk, qk;

int gcd(int a, int b) {
  int t;
  while(b) {
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}

int lcm(int a, int b) {
  return a*b/gcd(a, b);
}

void ass() {
  memcpy(bl, ans, 7*sizeof(int));
  int g=1;
  // calculate order of permutation
  for(i=0; i<7; ++i) {
    int n = bl[i];
    for(j=1; n!=i; ++j, n=bl[n]);
    g=lcm(g, j);
  }
  rk = (K/M-1)%g;
  for(i=0; i<rk; ++i) {
    for(j=0; j<7; ++j) bb[j]=ans[bl[j]];
    memcpy(ans, bb, 7*sizeof(int));
  }
  rk = K%M;
  for(i=0; i<rk; ++i) {
    int a = r[i][0], b = r[i][1];
    swap(ans[a], ans[b]);
  }
}

int main() {
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
      swap(ans[a], ans[b]);
      if(i+1 >= K) break;
    }
    if(i==M) ass();
    cout << '#' << test_case << ' ';
    for(i=0; i<7; ++i) cout << ans[i];
    cout << endl;
  }
  return 0;
}
