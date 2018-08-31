#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr[2001];
int cc[2000], cd[2000];
int main() {
  int i, j, k;
  scanf("%d", &N);
  int zz, ng;
  for(i=j=zz=ng=0; i<N; ++i) {
    int a;
    scanf("%d", &a);
    if(a == 0) ++zz;
    else {
      if(a<0) ++ng;
      arr[j++] = a;
    }
  }
  N = j;
  if(ng > N-ng) for(i=0; i<N; ++i) arr[i] = -arr[i];
  sort(arr, arr+N);
  for(i=k=0; i<N; i=j, ++k) {
    int val = arr[i], cnt=1;
    for(j=i+1; j<N && arr[j] == val; ++j) ++cnt;
    arr[k] = val;
    cc[k] = cd[k] = cnt;
  }
  N = k;

  int ans=0;
  arr[N] = 0x7fFFffFF;
  if(zz>0) for(i=0; i<N; ++i) {
    if(cc[i] >= 2) {
      ans += cd[i];
      cd[i] = 0;
    }
  }
  if(zz>2) {ans += zz; zz=0;}

  int x,y,lo,up;
  for(i=0; i<N-1; ++i) {
    x = arr[i];
    if(2*x > arr[N-1]) break;
    for(j=i+(cc[i]<2); j<N; ++j) {
      y=arr[j];
      if(x+y > arr[N-1]) break;
      if(x+y==0) {
        ans+=zz, zz=0;
        continue;
      }
      if(x<0 && y<0) lo=0, up=i;
      else if(x>0 && y>0) lo=j+1, up=N;
      else lo=i+1, up=j;
      int f = lower_bound(arr+lo, arr+up, x+y) - arr;
      if(arr[f] == x+y) {
        ans += cd[f];
        cd[f] = 0;
      }
    }
  }
  printf("%d", ans);
}
