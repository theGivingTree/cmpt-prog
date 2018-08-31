// after contest
#include <cstdio>
using namespace std;
int n, q, arr[200001];
bool deca[200000];
int chk[200001];
int main() {
  int i, j;
  scanf("%d%d",&n,&q);
  for(i=0; i<n; ++i) scanf("%d",arr+i);
  for(i=0; i<n && arr[i]==0; ++i);
  int last = a[i];
  int dec = false;
  for(++i; i<n; ++i) {
    int next = a[i];
    if(next == 0) continue;
    if(last < next) {
      if(dec) {
        puts("NO");
        return 0;
      }
      last = next;
    }
    else if(last > next) {
      dec = true;
      deca[i] = true;
      last = next;
    }
  }
  chk[0] = 0;
  for(i=1; i<n; ++i) {
    if(arr[i] >= arr[chk[i-1]]) chk[i] = chk[i-1];
    else chk[i] = i;
  }

  return 0;
}
