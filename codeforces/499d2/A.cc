#include <cstdio>
int N, K;
char str[55];
bool chk[26];
int main() {
  int i, j, ans=0;
  scanf("%d %d %s", &N, &K, str);
  for(i=0; i<N; ++i) chk[str[i]-'a']=true;
  for(i=0; i<26; ++i) if(chk[i]) break;
  if(i==26) {
    puts("-1");
    return 0;
  }
  ans += i+1;
  for(j=1; j<K; ++j) {
    for(i+=2; i<26; ++i) {
      if(chk[i]) {
        ans += i+1;
        break;
      }
    }
    if(i>=26) {
      puts("-1");
      return 0;
    }
  }
  printf("%d", ans);
  return 0;
}
