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

int n, m, a[1005];
int main() {
  int i, j;
  cin >> n >> m;
  priority_queue<int> q;
  for(i=0; i<n; ++i) {
    cin >> a[i];
    q.push(-a[i]);
  }

  for(i=0; i<m; ++i) {
    int a = -q.top(); q.pop();
    int b = -q.top(); q.pop();
    q.push(-(a+b));
    q.push(-(a+b));
  }

  LL sum = 0LL;
  for(i=0; i<n; ++i) {
    sum += -q.top();
    q.pop();
  }

  cout << sum;
  return 0;
}
