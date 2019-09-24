#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr[200000];
long long ans;
int enc(char *s) {
  return (s[0]-'A') + 26*(s[1]-'A');
}
int main() {
  int i;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    char q1[11], q2[3];
    scanf("%s %s", q1, q2);
    int e1 = enc(q1), e2 = enc(q2);
    arr[i] = e1 + 676*e2;
  }
  sort(arr, arr+N);
  int prev = arr[0], iii=0;
  for(i=1; i<N; ++i) {
    int x = arr[i];
    if(x != prev) {
      iii = i;
      prev = x;
    }
    int e1 = x%676, e2 = x/676;
    auto rg = equal_range(arr, arr+iii, e1*676 + e2);
    ans += rg.second - rg.first;
  }
  printf("%lld", ans);
  return 0;
}
