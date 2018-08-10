#include <cstdio>
#include <algorithm>
using namespace std;
int ans=0;
void f() {
  int N, a[9999], i;
  scanf("%d", &N);
  for(i=0; i<N; ++i) scanf("%d", a+i);
  sort(a, a+N);
  for(i=0; i+1<N && a[i+1]<=0; i+=2) ans+=a[i]*a[i+1];
  if(i>=N) return;
  if(a[i]<=0) ans+=a[i++];
  if((N-i)%2) ans+=a[i++];
  for(; a[i]==1 && i<N; i+=2) ans+=a[i]+a[i+1];
  for(; i<N; i+=2) ans+=a[i]*a[i+1];
}
int main() {
  f();
  printf("%d", ans);
}
