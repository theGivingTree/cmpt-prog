#include <iostream>
using namespace std;
constexpr unsigned MASK = 0x0000ffff;
int N;
char strA[20], strB[20]; // safe size
int lenA, lenB;
unsigned used;
bool go(int n, unsigned u) {
  if(n==-1) {
    return false;
  }
  if(n==0) {
    unsigned ua = u&MASK;
    ua &= ~(1<<10);
    if(ua == 0 || ua == 1<<0) return false;
    else return true;
  }

  unsigned utot = (u&MASK) | u>>16;
  int i, j;
  int dig = n%10;

  if(!(utot & 1<<dig)) {
    // dig = (empty)+dig
    // 10-th bit kicks in
    if(go(n/10, u | 1<<10 | 1<<(dig+16))) {
      strB[lenB++] = '0' + dig;
      return true;
    }
  }
  if(u & 1<<10) return false;

  // dig = i + j (i<j)
  int smallerBound = (dig-1)/2;
  if(dig == 0) smallerBound = -1;
  // non-carry
  for(i=0; i<=smallerBound; ++i) {
    j = dig - i;
    if(utot & 1<<i || utot & 1<<j) continue;
    if(go(n/10, u | 1<<i | 1<<(j+16))) {
      strA[lenA++] = '0' + i;
      strB[lenB++] = '0' + j;
      return true;
    }
  }

  dig += 10;
  smallerBound = (dig-1)/2;
  // carry
  for(i=dig-9; i<=smallerBound; ++i) {
    j = dig - i;
    if(utot & 1<<i || utot & 1<<j) continue;
    if(go(n/10-1, u | 1<<i | 1<<(j+16))) {
      strA[lenA++] = '0' + i;
      strB[lenB++] = '0' + j;
      return true;
    }
  }

  return false;
}
using namespace std;
int main() {
  cin >> N;
  if(go(N, used)) {
    cout << strA << " + " << strB << '\n';
  }
  else {
    cout << "-1\n";
  }
}
