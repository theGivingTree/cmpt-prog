#include <iostream>
using namespace std;
int T, test_case;
int N;
int main() {
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N;
    int dum;
    for(int i=0; i<=N; ++i) cin >> dum;
    cout << "Case #" << test_case << ": " << (N%2?1:0) << '\n';
    if(N%2) cout << 0.0 << '\n';
  }
  return 0;
}
