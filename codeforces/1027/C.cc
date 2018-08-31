#include <cstdio>
#include <cfloat>
#include <algorithm>
using namespace std;
int arr[1000001];
int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int i, j;
    double ans = 0;
    int ans1=0, ans2=0;
    int n;
    scanf("%d", &n);
    for(i=0; i<n; ++i) scanf("%d", arr+i);
    sort(arr, arr+n);

    arr[n] = 0;
    i=0;
    while(i<n) {
      int a, b, cnt, nexti;
      j=i;
      a = arr[j];
      cnt = 0;
      while(j<n && a==arr[j]) ++cnt, ++j;
      if(cnt<2) {
        i=j;
        continue;
      }

      if(cnt>=4) {
        ans1=ans2=a;
        break;
      }

      do {
        nexti = j;
        b = arr[j];
        cnt = 0;
        while(j<n && b==arr[j]) ++cnt, ++j;
      } while(j<n && cnt < 2);
      if(cnt<2) {
        break;
      }

      if(ans < 1.0*a/b) {
        ans = 1.0*a/b;
        ans1 = a;
        ans2 = b;
      }

      i=nexti;
    }

    printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
  }
  return 0;
}
