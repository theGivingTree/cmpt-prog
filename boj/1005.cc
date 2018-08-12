#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int TC;
int N, K, W, bt[1000], accbt[1000], chc[1000];
vector<int> par[1000];
void solve() {
  int i, j;
  cin >> N >> K;
  memset(chc, 0, sizeof(int)*N);
  memset(accbt, 0, sizeof(int)*N);
  for(i=0; i<N; ++i) {
    par[i].clear();
    cin >> bt[i];
  }
  for(i=0; i<K; ++i) {
    int x, y;
    cin >> x >> y; --x, --y;
    ++chc[y];
    par[x].push_back(y);
  }
  cin >> W; --W;
  queue<int> q;
  for(i=0; i<N; ++i) {
    if(chc[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    int x = q.front(); q.pop();
    accbt[x] += bt[x];
    if(x == W) {
      cout << accbt[x] << '\n';
    }

    for(int p: par[x]) {
      if(accbt[p] < accbt[x]) accbt[p] = accbt[x];

      if(--chc[p] == 0) {
        q.push(p);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> TC;
  while(TC--) {
    solve();
  }
  return 0;
}
