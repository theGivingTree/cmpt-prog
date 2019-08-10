#include <iostream>
using namespace std;
int T, test_case, ans;
int N, B, S;
int main() {
  cin >> T;
  int *dd = new int[1<<19];
  for(test_case=1; test_case<=T; ++test_case) {
    int i, j;
    cin >> N >> B;
    ans = 0x7fffffff;
    S = 0;
    for(i=0; i<N-1; ++i) {
      int v;
      cin >> v;
      dd[1<<i] = v;
      S += v;
    }
    int last;
    cin >> last;
    S += last;
    for(i=0; i<1<<(N-1); ++i) {
      j = i&-i;
      dd[i] = dd[j] + dd[i&~j];
      if(dd[i] >= B && ans > dd[i]) ans = dd[i];
      if(S-dd[i] >= B && ans > S-dd[i]) ans = S-dd[i];
    }
    cout << '#' << test_case << ' ' << ans-B << endl;
  }
  return 0;
}
