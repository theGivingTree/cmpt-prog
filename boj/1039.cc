#include <cstdio>
using namespace std;
char s[8];
int len, K;
int main() {
  int N;
  int i, j;
  scanf("%s %d", s, &K);
  sscanf(s, "%d", &N);
  for(len=0; s[len]; ++len);
  if(len==1 || len==2 && s[1]=='0') {
    puts("-1");
    return 0;
  }
  for(i=0; i<len-1 && K; ++i) {
    int II = i;
    for(j=len-1; j>i; --j) {
      if(s[j] > s[II]) II = j;
    }
    if(II == i) continue;
    --K;
    char t=s[II];s[II]=s[i];s[i]=t;
  }
  if(K%2 == 1) {
    bool flag = false;
    for(i=0; i<len; ++i) for(j=i+1; j<len; ++j) {
      if(s[i] == s[j]) flag = true;
    }
    if(!flag) {
      char t=s[len-1];s[len-1]=s[len-2];s[len-2]=t;
    }
  }
  puts(s);
  return 0;
}
