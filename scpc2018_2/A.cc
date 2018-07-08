#include <iostream>
using namespace std;
int T, test_case, N, maxa, ans, mina, av[200000], minas[200000];
int main() {
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N;
    maxa = 0;
    mina = 0x7fffffff;
    ans = 0;
    for(int i=0; i<N; ++i) {
      int a;
      cin >> a;
      av[i]=minas[i]=a;
    }
    for(int i=N-1; i>=0; --i) {
      int t = minas[i];
      minas[i] = mina;
      if(mina > t) mina = t;
    }
    for(int i=0; i<N; ++i) {
      if(maxa < av[i]) {
        maxa = av[i];
        if(av[i] < minas[i]) ++ans;
      }
    }
    cout << "Case #" << test_case << '\n' << ans << '\n';
  }
  return 0;
}
