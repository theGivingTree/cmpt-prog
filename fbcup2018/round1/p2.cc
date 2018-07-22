#include <iostream>
#include <queue>
using namespace std;

int T, test_case;
struct DFS {
  int order=0;
  int idxArr[2222], orderArr[2222];
  void visit(int x) {
    idxArr[order] = x;
    orderArr[x] = order;
    ++order;
  }
};

int N, K, lc[2222], rc[2222], label[2222];
void preOrder(int u, DFS& obj) {
  obj.visit(u);
  if(lc[u]) preOrder(lc[u], obj);
  if(rc[u]) preOrder(rc[u], obj);
}
void postOrder(int u, DFS& obj) {
  if(lc[u]) postOrder(lc[u], obj);
  if(rc[u]) postOrder(rc[u], obj);
  obj.visit(u);
}

int main() {
  int i, j, k;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> N >> K;
    for(i=1; i<=N; ++i) {
      cin >> lc[i] >> rc[i];
      label[i] = 0;
    }

    DFS dfsObj1, dfsObj2;
    preOrder(1, dfsObj1);
    postOrder(1, dfsObj2);

    queue<int> q; // index-queue
    int nextIdx = 1;
    for(k=1; k<=K; ++k) {

      while(label[nextIdx] && nextIdx<=N) ++nextIdx;
      if(nextIdx > N) {
        // label-k, not usabled
        break;
      }

      q.push(nextIdx);
      while(!q.empty()) {
        int len = q.size();
        for(i=0; i<len; ++i) {
          int idx = q.front();
          if(label[idx] == k) {
            q.pop();
            continue;
          }
          q.pop();
          label[idx] = k;

          int order1, order2;
          order1 = dfsObj1.orderArr[idx];
          order2 = dfsObj2.orderArr[idx];
          q.push(dfsObj1.idxArr[order2]);
          q.push(dfsObj2.idxArr[order1]);
        }
      }
    }

    cout << "Case #" << test_case << ":";
    if(k<=K) {
      cout << " Impossible";
    }
    else {
      for(i=1; i<=N; ++i) {
        int v = label[i];
        if(!v) v = 1;
        cout << ' ' << v;
      }
    }
    cout << '\n';
  }
  return 0;
}
