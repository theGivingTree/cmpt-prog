#include <iostream>
using namespace std;
using LL = long long;
int T, test_case;
LL ans;
int N, M, perf[100000];
int main() {
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    LL lo=0x7fffffff, hi, t;

    cin >> N >> M;
    for(int i=0; i<N; ++i) {
      cin >> perf[i];
      if(lo > perf[i]) lo = perf[i];
    }

    ans = hi = lo*M;
    while(lo<=hi) {
      t = (lo+hi)/2;
      LL sum = 0;
      for(int i=0; i<N; ++i) {
        sum += t/perf[i];
      }

      if(sum < M) {
        lo = t+1;
      }
      else {
        ans = t;
        hi = t-1;
      }
    }

    cout << '#' << test_case << ' ' << ans << endl;
  }
  return 0;
}
