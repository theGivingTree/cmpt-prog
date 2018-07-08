/* Tourist */
#include <iostream>
#include <queue>
using namespace std;

struct Attr {
  int idx, vcnt;
  bool operator<(Attr const rhs) const {
    return (vcnt > rhs.vcnt) or (vcnt == rhs.vcnt and idx > rhs.idx);
  }
} attrs[50];

using PQ = priority_queue<Attr>;
using LL = long long;

int N, K;
LL V;
char titles[50][21];
bool ansbool[50];

int gcd(int a, int b) {
  int t;
  while(b) {
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}

int main() {
  int T, test_case;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N >> K >> V;
    int g, period;
    g = gcd(N, K);
    period = N/g;
    V = (V-1)%period+1;

    PQ pq;
    for(int i=0; i<N; ++i) {
      cin >> titles[i];
      pq.push({i, 0});
    }
    for(int i=0; i<V-1; ++i) {
      for(int j=0; j<K; ++j) {
        auto e = pq.top();pq.pop();
        ++e.vcnt;
        pq.push(e);
      }
    }

    for(int j=0; j<N; ++j) ansbool[j]=false;
    for(int j=0; j<K; ++j) {
      auto e = pq.top();pq.pop();
      ansbool[e.idx]=true;
    }
    cout << "Case #" << test_case << ":";
    for(int j=0; j<N; ++j) {
      if(!ansbool[j]) continue;
      cout << ' ' << titles[j];
    }
    cout << '\n';
  }
  return 0;
}
