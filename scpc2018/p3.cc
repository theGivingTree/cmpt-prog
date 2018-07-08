#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int Answer;
int N, M;
vector<set<int>> vlist;

int gogo(int u) {
  if(vlist[u].size() != 2) return 0;
  auto it = vlist[u].begin();
  int v = *it, w = *(++it);

  it = vlist[v].find(w);
  if(it == vlist[v].end()) return 0;

  vlist[v].erase(u);
  vlist[w].erase(u);
  vlist[u].erase(v);
  vlist[u].erase(w);

  return 1 + gogo(v) + gogo(w);
}

int main() {
  int T, test_case;
  int i;
  cin >> T;
  for(test_case = 0; test_case  < T; test_case++) {

    cin >> N >> M;
    vlist.resize(N+1);
    for(i=1; i<=N; ++i) {
      vlist[i].clear();
    }
    for(i=0; i<M; ++i) {
      int u, v;
      cin >> u >> v;
      vlist[u].insert(v);
      vlist[v].insert(u);
    }

    Answer = 0;
    for(i=1; i<=N; ++i) Answer += gogo(i);

    cout << "Case #" << test_case+1 << endl;
    cout << N - Answer << endl;
  }

  return 0;
}
