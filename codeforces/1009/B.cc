#include <cstdio>
#include <cstring>
using namespace std;
char s[100001];
char buf[10000];
void strswap(int x, int y, int z) {
  strncpy(buf, s+y, z-y);
  strncpy(buf+(z-y), s+x, y-x);
  strncpy(s+x, buf, z-x);
}
int main() {
  int i, j;
  scanf("%s", s);
  i=0;
  while(s[i]) {
    if(s[i] == '0') {
      putchar('0');
      ++i;
      continue;
    }

    if(s[i] == '1') {
      j=i;
      int s0=0, s1=0;
      while(s[j] && s[j]!='2') {
        if(s[j] == '0') ++s0;
        else ++s1;
        ++j;
      }
      int k=i;
      for(; s0>0; ++k, --s0) {
        putchar('0');
        // s[k]='0';
      }
      for(; s1>0; ++k, --s1) {
        putchar('1');
        // s[k]='1';
      }
      i=j;
    }
    else {
      j=i;
      int s1=0;
      while(s[j]) {
        if(s[j] == '1') ++s1;
        ++j;
      }

      int k=i;
      for(; s1>0; ++k, --s1) {
        putchar('1');
        //s[k]='1';
      }
      int kk=i;
      for(; s[kk]; ++kk) {
        if(s[kk] != '1') {
          putchar(s[kk]);
          // s[k++] = s[kk];
        }
      }

      i=j;
    }
  }
  return 0;
}
