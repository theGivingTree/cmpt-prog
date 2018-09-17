#include <cstdio>
#include <cstring>
using namespace std;
char str[1000001];
int main() {
  int i=0;
  while(true) {
    char d=getchar();
    if(d!='P' && d!='A') break;
    str[i++] = d;
    if(i>=4) {
      if(strncmp("PPAP", str+i-4, 4) == 0) i-=3;
    }
  }
  if(i == 1 && str[0] == 'P') puts("PPAP");
  else puts("NP");
  return 0;
}
