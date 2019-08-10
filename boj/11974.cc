#include <cstdio>
#include <vector>
using namespace std;
int N;
int qq[7], ww[7];
int main() {
  int i;
  scanf("%d",&N);
  int s=0;
  for(i=1;i<=N;++i) {
    int a;
    scanf("%d",&a);
    s+=a;
    s%=7;
    if(s==0) ww[0]=i;
    else {
      if(!qq[s]) qq[s]=i;
      ww[s]=i;
    }
  }
  int ans=0;
  for(i=0; i<7; ++i) {
    if(ans < ww[i]-qq[i]) ans = ww[i]-qq[i];
  }
  printf("%d", ans);
  return 0;
}
