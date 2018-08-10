#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, Q;
int x_sorted[250000], y_sorted[250000];

int parent[250001][18], dd[250001];

int cost[250001][18];
struct CP {
  int id;
  int x, y, idx_x, idx_y;
} cpl[250001];

struct CompareX {
  bool operator()(int i, int j) const {
    return cpl[i].x < cpl[j].x;
  }
};
struct CompareY {
  bool operator()(int i, int j) const {
    return cpl[i].y < cpl[j].y;
  }
};

struct QNode {
  int idx, dis, pidx;
  bool operator<(QNode rhs) const {
    return dis > rhs.dis;
  }
};

void addNext(priority_queue<QNode>& q, QNode node) {
  auto const& cp = cpl[node.idx];
  int idxToX = cp.idx_x;
  int idxToY = cp.idx_y;

  if(idxToX-1 >= 0) {
    int idxNext = x_sorted[idxToX-1];
    auto const& cpNext = cpl[idxNext];
    q.push({idxNext, abs(cp.x-cpNext.x), node.idx});
  }
  if(idxToX+1 < N) {
    int idxNext = x_sorted[idxToX+1];
    auto const& cpNext = cpl[idxNext];
    q.push({idxNext, abs(cp.x-cpNext.x), node.idx});
  }
  if(idxToY-1 >= 0) {
    int idxNext = y_sorted[idxToY-1];
    auto const& cpNext = cpl[idxNext];
    q.push({idxNext, abs(cp.y-cpNext.y), node.idx});
  }
  if(idxToY+1 < N) {
    int idxNext = y_sorted[idxToY+1];
    auto const& cpNext = cpl[idxNext];
    q.push({idxNext, abs(cp.y-cpNext.y), node.idx});
  }
}

int lca(int x, int y) {
  int i;
  if(dd[x] < dd[y]) swap(x, y);
  int diff;
  int maxVal = 0;
  for(i=0, diff=dd[x]-dd[y]; diff; ++i, diff>>=1) {
    if((diff&1)==0) continue;
    if(maxVal < cost[x][i]) maxVal = cost[x][i];
    x = parent[x][i];
  }

  if(x==y) return maxVal;

  for(i=18; i--;) {
    if(parent[x][i] != parent[y][i]) {
      if(maxVal < cost[x][i]) maxVal = cost[x][i];
      x=parent[x][i];
      if(maxVal < cost[y][i]) maxVal = cost[y][i];
      y=parent[y][i];
    }
  }

  return max({maxVal, cost[x][0], cost[y][0]});
}

// int CpIdx_TreeIdx[250001];

int main() {
  int i, j;
  scanf("%d %d", &N, &Q);
  for(i=1; i<=N; ++i) {
    cpl[i].id = i;
    scanf("%d %d", &cpl[i].x, &cpl[i].y);
    x_sorted[i-1] = i;
    y_sorted[i-1] = i;
  }
  sort(x_sorted, x_sorted+N, CompareX());
  sort(y_sorted, y_sorted+N, CompareY());

  for(i=0; i<N; ++i) {
    int idx = x_sorted[i];
    cpl[idx].idx_x = i;
  }
  for(i=0; i<N; ++i) {
    int idx = y_sorted[i];
    cpl[idx].idx_y = i;
  }

  priority_queue<QNode> q;
  q.push({1, 0, 0}); // idx(for cpl), dis, parent_idx
  dd[0] = 0;
  for(j=0; j<18; ++j) parent[0][j] = 0;

  for(i=0; i<N; ++i) {
    QNode nd;
    while(true) {
      nd = q.top(); q.pop();
      if(dd[nd.idx]) continue;
      break;
    }

    dd[nd.idx] = dd[nd.pidx] + 1;
    // CpIdx_TreeIdx[cpl[nd.idx].id] = nd.idx;
    parent[nd.idx][0] = nd.pidx;
    cost[nd.idx][0] = nd.dis;

    addNext(q, nd);
  }

  for(j=1; j<18; ++j) {
    for(i=2; i<=N; ++i) {
      int half = parent[i][j-1];
      int full = parent[half][j-1];
      parent[i][j] = full;
      cost[i][j] = max(cost[i][j-1], cost[half][j-1]);
    }
  }

  for(i=0; i<Q; ++i) {
    int A, B, X;
    scanf("%d %d %d", &A, &B, &X);
    // A = CpIdx_TreeIdx[A];
    // B = CpIdx_TreeIdx[B];
    if(lca(A, B) <= X) {
      puts("YES");
    }
    else {
      puts("NO");
    }
  }

  return 0;
}
