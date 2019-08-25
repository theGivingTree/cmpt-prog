#include <cstdio>
#include <cstring>
using namespace std;
char ss[31];
int ss_len;
long long N;
int main() {
  scanf("%s%lld", ss, &N);
  ss_len = strlen(ss);
  long long a;
  for(a=ss_len; N>a*2; a*=2);
  while(N>ss_len) {
    if(N>a) {
      N=N-a-1;
      if(N==0) N=a;
    }
    a/=2;
  }
  printf("%c",ss[N-1]);
  return 0;
}
