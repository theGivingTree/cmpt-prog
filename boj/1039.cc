#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char ns[8];
int K;
bool dup;
int ns_l, w[7];
int go(int s, int kz) {
  if(kz == 0) return strtol(ns+s, NULL, 10);

  int v, i, p = 0;
  while(ns_l - s > 2) {
    v = s;
    for(i=s+1; i<ns_l; ++i) {
      if(ns[v] < ns[i]) v = i;
    }
    p += (ns[v]-'0')*w[s];
    if(v != s) break;
    ++s;
  }

  if(ns_l - s == 2) {
    int a = (ns[s]-'0')*10 + (ns[s+1]-'0'), b = (ns[s+1]-'0')*10 + (ns[s]-'0');
    if(dup) return p+(a<b?b:a);
    else return p+(kz%2?b:a);
  }

  int xm = 0;
  for(i=v; i<ns_l; ++i) {
    if(ns[v] == ns[i]) {
      char t=ns[i];ns[i]=ns[s];ns[s]=t;
      int x = go(s+1, kz-1);
      if(xm < x) xm = x;
      t=ns[i];ns[i]=ns[s];ns[s]=t;
    }
  }

  return p + xm;
}
int main() {
  int i, j;
  scanf("%s %d",ns,&K);
  ns_l = strlen(ns);
  if(ns_l==1 || ns_l==2 && ns[1] == '0') { puts("-1"); return 0; }

  dup = false;
  w[ns_l-1] = 1;
  for(i=ns_l-2; i>=0; --i) w[i] = w[i+1]*10;
  for(i=0; i<ns_l-1; ++i) {
    for(j=i+1; j<ns_l; ++j) {
      if(ns[i] == ns[j]) {
        dup = true;
        goto _exit_loop;
      }
    }
  }
_exit_loop:

  printf("%d", go(0, K));
  return 0;
}
