#include <cstdio>
using namespace std;
int dd[] = {
  0b111101101101111,
  0,
  0b111001111100111,
  0b111001111001111,
  0b101101111001001,
  0b111100111001111,
  0b111100111101111,
  0b111001001001001,
  0b111101111101111,
  0b111101111001111
};
int n;
char pat[100001];
int par(int &x) {
  int i, j;
  int s = 0;
  for(i=0; i<5; ++i) {
    for(j=0; j<3; ++j) {
      char ch = pat[n*i + x+j];
      s<<=1;
      if(ch == '#') ++s;
    }
  }
  for(i=0; i<10; ++i) {
    if(dd[i] == s) {
      x+=3;
      return i;
    }
  }
  x+=1;
  return 1;
}
int main() {
  int i, j;
  scanf("%d %s", &n, pat);
  n/=5;
  for(i=0; i<n;) {
    if(pat[i] == '.') {
      ++i;
      continue;
    }
    printf("%d", par(i));
  }
  return 0;
}
