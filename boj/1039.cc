#include <cstdio>
#include <algorithm>
using namespace std;
char s[8];
int len, K;
int main() {
  int i, j;
  scanf("%s %d", s, &K);
  for(len=0; s[len]; ++len);
  if(len==1 || len==2 && s[1]=='0') {
    puts("-1");
    return 0;
  }
  for(i=0; i<len-1 && K; ++i) {
    int II = i;
    int cnt = 0;
    for(j=i+1; j<len; ++j) {
      if(s[II] == s[j]) ++cnt;
      else if(s[II] < s[j]) {
        cnt = 0;
        II = j;
      }
    }
    if(II == i) continue;

    if(cnt == 0) {
      --K;
      char t=s[II];s[II]=s[i];s[i]=t;
    }
    else {
      ++cnt;
      char sII = s[II];
      int swps = 0;
      char tmp[4];
      for(j=i; j<i+cnt && swps < K; ++j) {
        if(sII != s[j]) {
          tmp[swps++] = s[j];
          s[j] = sII;
        }
      }

      int ii, jj;
      for(ii=swps; ii-->1;) for(jj=0; jj<ii; ++jj) if(tmp[jj]<tmp[jj+1]) swap(tmp[jj], tmp[jj+1]);

      K -= swps;
      for(j=len-1; swps>0; --j) {
        if(sII == s[j]) s[j] = tmp[--swps];
      }
      j=i+1;
      while(s[j] == sII) ++j;
      i = j-1;
    }
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
