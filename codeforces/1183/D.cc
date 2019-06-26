#include <cstdio>
#include <algorithm>
using namespace std;
int sol() {
  int i;
  int n, arr[200000];
  scanf("%d",&n);
  for(i=0; i<n; ++i) arr[i] = 0;
  for(i=0; i<n; ++i) {
    int t;
    scanf("%d",&t);
    ++arr[t-1];
  }
  sort(arr, arr+n);
  int x = arr[n-1];
  int ret = x;
  for(i=n-2; x && i>=0; --i) {
    if(arr[i] >= x) {
      ret += --x;
    }
    else {
      ret += arr[i];
      x = arr[i];
    }
  }

  return ret;
}
int main() {
  int q;
  scanf("%d",&q);
  while(q--) printf("%d\n", sol());
  return 0;
}
