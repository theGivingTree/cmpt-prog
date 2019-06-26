#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef priority_queue<int> PQ;
struct QQ {
  int n, c;
  bool operator<(QQ const &rhs) const {
    return n < rhs.n || (n == rhs.n && c < rhs.c);
  }
};
QQ sol() {
  int i;
  int n;
  QQ arr[200000];
  scanf("%d",&n);
  for(i=0; i<n; ++i) arr[i] = {0, 0};
  for(i=0; i<n; ++i) {
    int t, f;
    scanf("%d%d",&t,&f);
    ++arr[t-1].n;
    if(f) ++arr[t-1].c;
  }
  sort(arr, arr+n);

  int y = arr[n-1].n - 1;
  QQ ret = arr[n-1];
  PQ pq;

  for(i=n-2; y;) {
    if(i<0 || arr[i].n < y) {
      if(pq.empty()) {
          y = arr[i].n;
      }
      else {
        int c = pq.top(); pq.pop();
        ret.n += y;
        ret.c += min(c, y);
        --y;
      }
    }

    if(i>=0) {
      if(arr[i].n > 0) pq.push(arr[i].c);
      --i;
    }
  }

  return ret;
}
int main() {
  int q;
  scanf("%d",&q);
  while(q--) {
    QQ s = sol();
    printf("%d %d\n", s.n, s.c);
  }
  return 0;
}
