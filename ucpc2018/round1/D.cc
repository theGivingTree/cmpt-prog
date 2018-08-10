#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using LL = long long;

int N;
vector<int> alist[500010];

int dfs(int pu, int u, int dp) {
  int i,j;
  auto& list = alist[u];
  int size = list.size();
  if(pu != 0 && size == 1) {
    return dp%2;
  }
  int xsum = 0;
  for(i=0; i<size; ++i) {
    int v = list[i];
    if(v == pu) continue;
    xsum = (xsum + dfs(u, v, dp+1))%2;
  }
  return xsum;
}

int main() {
  int i, j;
  scanf("%d", &N);
  for(i=1; i<N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    alist[a].push_back(b);
    alist[b].push_back(a);
  }
  int xsum = dfs(0, 1, 0);
  if(xsum == 1) {
    puts("Yes");
  }
  else {
    puts("No");
  }
  return 0;
}
