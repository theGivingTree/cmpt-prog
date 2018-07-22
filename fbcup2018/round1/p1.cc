#include <iostream>
using namespace std;
constexpr int MOD = 1'000'000'007;
int T, test_case, N;
char mm[3][1001];
int a, b, c, aa, bb, cc;
int main() {
  int i, j;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N;
    for(i=0; i<3; ++i) {
      cin >> mm[i];
    }
    a=1, b=0, c=0;
    for(i=0; i<N; ++i) {
      char b1=mm[0][i], b2=mm[1][i], b3=mm[2][i];
      aa=0, bb=0, cc=0;
      if(b1 != '#' && b2 != '#') {
        aa = b;
        bb += a;
      }
      if(b2 != '#' && b3 != '#') {
        cc = b;
        bb += c;
      }
      a=aa%MOD, b=bb%MOD, c=cc%MOD;
    }
    cout << "Case #" << test_case << ": " << c << '\n';
  }
}
