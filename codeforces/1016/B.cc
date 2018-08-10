#include <cstdio>
using namespace std;
int n, m, q;
char s[1001], t[1001];
int fe[1001];
void kmp_init(int fe[], char pat[], int len) {
  int i, j;
  i=0;
  fe[0] = j = -1;
  while(i<len) {
    while(j != -1 && pat[i] != pat[j]) j = fe[j];
    ++i, ++j;
    if(pat[i] == pat[j]) fe[i] = fe[j];
    else fe[i] = j;
  }
}
int main() {
  int i, j;
  scanf("%d %d %d %s %s", &n, &m, &q, s, t);
  kmp_init(fe, t, m);
  for(i=0; i<q; ++i) {
    int a, b, res;
    scanf("%d %d", &a, &b);
    int len = b-a+1;
    char *ss = s+(a-1);
    
    int ii, jj;
    ii=0, jj=0;
    res = 0;
    while(ii<len) {
      while(jj != -1 && ss[ii] != t[jj]) jj = fe[jj];
      ++ii, ++jj;
      if(jj == m) {
        ++res;
        jj = fe[jj];
      }
    }
    printf("%d\n", res);
  }
}
