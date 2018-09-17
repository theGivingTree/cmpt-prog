#include <cstdio>
using namespace std;
int n;
char s[51], t[51];
int cnt[26];
int bb[25*49], bblen;
int main() {
  int i, j, k;
  scanf("%d %s %s", &n, s, t);
  for(i=0; i<n; ++i) {
    ++cnt[s[i]-'a'];
    --cnt[t[i]-'a'];
  }
  for(i=0; i<26 && cnt[i]==0; ++i);
  if(i<26) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  for(i=0; s[i]; ++i) {
    if(s[i] == t[i]) continue;
    for(j=i+1; s[j]!=t[i]; ++j);
    ans += j-i;
    for(k=j-1; k>=i; --k) {
      s[k+1] = s[k];
      bb[bblen++] = k;
    }
    s[i]=s[i];
  }
  printf("%d\n", ans);
  for(i=0; i<bblen; ++i) printf("%d ", 1+bb[i]);
  return 0;
}
