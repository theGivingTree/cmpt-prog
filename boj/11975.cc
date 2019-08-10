#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr[1001], sss[1000];
int main() {
  int i, j;
  int x=1<<10, y=1<<10;
  arr[0]=x<<11 | y;
  scanf("%d ", &N);
  for(i=1; i<=N; ++i) {
    char ch = getchar();
    int f=0;
    int sx=x, sy=y;
    if(ch=='S') x++;
    else if(ch=='E') y++, f=1;
    else if(ch=='N') --x, --sx;
    else --y, --sy,  f=1;

    arr[i]=x<<11 | y;
    sss[i-1]=f<<22 | sx<<11 | sy;
  }
  sort(arr, arr+(N+1));
  sort(sss, sss+N);

  int ans=0, pv;
  i=0;
  while(i<=N) {
    pv=arr[i];
    j=i;
    while(i<=N && pv==arr[++i]);
    ans += i-j-1;
  }

  i=0;
  while(i<N) {
    pv=sss[i];
    j=i;
    while(i<N && pv==sss[++i]);
    ans -= i-j-1;
  }
  printf("%d\n", ans);
  return 0;
}
