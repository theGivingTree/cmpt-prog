#include <cstdio>
using namespace std;
int n;
char s[100001];
int cc[26];
int main() {
  int i, j;
  scanf("%d%s", &n,s);
  for(i=0;s[i];++i) {
    ++cc[s[i]-'a'];
  }
  bool ans = false;
  for(i=0; i<26; ++i) {
    if(cc[i] >= 2) {
      ans = true;
      break;
    }
  }
  puts(ans || n==1?"YES":"NO");
  return 0;
}
