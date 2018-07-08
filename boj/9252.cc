#include <cstdio>
#include <cstring>
using namespace std;
char sa[1001], sb[1001];
int la, lb, ll;
int d[1001][1001], t[1001];
int main() {
  int i, j, n;
  scanf("%s %s", sa, sb);
  ll=la=strlen(sa);
  lb=strlen(sb);
  if(ll<lb) ll=lb;
  for(n=1; n<=ll; ++n) {
    i=n;
    for(j=1; j<=ll; ++j) {
      int a=d[i][j-1], b=d[i-1][j], c;
      d[i][j]=a>b?a:(t[i]=t[i-1],b);
      c = sa[i-1]==sb[j-1]?d[i-1][j-1]+1:0;
      if(d[i][j]<c) {
        t[i]=i;
        d[i][j]=c;
      }
    }
  }
  for(i=1; i<=la; ++i) {
    printf("--> %d, %d\n", i, t[i]);
  }
  int Q=d[ll][ll];
  printf("%d\n", Q);
  sb[Q]=0;
  i=la;
  while(t[i]) {
    sb[--Q]=sa[t[i]-1];
    printf("->%d, %d\n", t[i], Q);
    i=t[i]-1;
  }
  puts(sb);
  return 0;
}
