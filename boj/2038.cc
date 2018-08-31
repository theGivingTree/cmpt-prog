#include <cstdio>
#include <queue>
using namespace std;
int n;
int main() {
  int i, j, k;
  scanf("%d", &n);
  if(n==1) {
    puts("1");
    return 0;
  }
  else if(n<=3) {
    puts("2");
    return 0;
  }
  else if(n<=5) {
    puts("3");
    return 0;
  }
  queue<pair<int, int>> qu;
  qu.push({3, 2});
  i=5, j=4;
  while(true) {
    int a, b;
    auto e = qu.front(); qu.pop();
    a = e.first, b = e.second;
    for(k=0; k<b; ++k, ++j) {
      qu.push({j, a});
      i+=a;
      if(i>=n) {
        printf("%d", j);
        return 0;
      }
    }
  }
  return 0;
}
