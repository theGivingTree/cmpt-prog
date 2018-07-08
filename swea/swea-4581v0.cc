#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int T, test_case;
char a[30001];
void ppp(int in, int ex) {
  char c=a[ex];
  a[ex]=0;
  cout << a+in;
  a[ex]=c;
}
int main() {
  int i, j;
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> a;
    cout << '#' << test_case << ' ';
    i = 0;
    j = strlen(a) - 1;
    while(i<j) {
      char b=a[i], c=a[j];
      if(b<c) cout << b, ++i;
      else if(b>c) cout << c, --j;
      else {
        int ix=i+1, jx=j-1;
        int pad = 0, pad2 = 0;
        while(ix<jx && a[ix]==a[jx] && a[ix] < b) {
          ++ix, --jx;
        }
        while(ix<jx && a[ix]==a[jx] && a[ix] <= b) {
          ++ix, --jx;
          ++pad;
        }
        while(ix<jx && a[ix]==a[jx]) {
          ++ix, --jx;
          ++pad2;
        }
        if(pad > 0) pad += pad2;

        if(ix>jx) {
          if(pad == 0) {
            if(pad2 == 0) {
              ppp(i, j+1);
              i=j+1;
            }
            else {
              ppp(i, ix-pad2);
              ppp(i, ix-pad2);
              i=ix-pad2, j=jx+pad2;
            }
          }
          else {
            ppp(i, ix-pad);
            i=ix-pad;
          }
          continue;
        }

        char d=a[ix], e=a[jx];
        if(d > b && e > b && pad == 0) {
          ppp(i, ix-pad2);
          ppp(i, ix-pad2);
          i=ix-pad2, j=jx+pad2;
        }
        else {
          if(pad == 0) {
            ppp(i, ix-pad2);
            if(pad2 == 0) {
              cout << (d<e?d:e);
              pad = -1;
            }
            else pad = pad2;
          }
          else ppp(i, ix-pad);

          if(d<e) i=ix-pad;
          else j=jx+pad;
        }
      }
    }
    if(i==j) cout << a[i];
    cout << '\n';
  }
  return 0;
}
