#include <cstdio>
#include <vector>
int T, test_case;
int N, M, _A_, _B_;
vector<int> children[200000];
int parent[200000];
bool tag[200000];

void init() {
  for(i=0; i<=N; ++i) children[0].empty();
  for(i=1; i<=N; ++i) tag[i] = false;
}



int main() {
  scanf("%d", &T);
  for(test_case=1; test_case<=T; ++test_case) {
    int i, j;
    scanf("%d %d %d %d", &N, &M, &_A_, &_B_);

    init();
    for(i=1; i<N; ++i) {
      int par;
      scanf("%d", &par);
      parent[i] = par;
      children[par].push_back(i):
    }
    for(i=0; i<M; ++i) {
      int C = (1LL_A_*i + B)%N;
      tag[C] = true;
    }

    dfs(0);

    printf("Case #%d: %d\n", test_case, -1);
  }
}
