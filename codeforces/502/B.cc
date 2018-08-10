#include <iostream>
using namespace std;
int const N_MAX = 100000;
int N;
char s[N_MAX+5], t[N_MAX+5];
// int oz[N_MAX+1], zz[N_MAX+1], zeros[N_MAX+1], ones[N_MAX+1];
int main() {
  int i;
  cin >> N;
  cin >> s >> t;
  long long ans = 0;
  int oz, zz, zeros, ones;
  oz=zz=zeros=ones=0;
  for(i=0; i<N; ++i) {
    int sd = s[i] - '0', td = t[i] - '0';

    if(!sd && td) {
      ans += oz;
    }
    else if(sd && td) {
      ans += zz;
    }
    else if(sd && !td) {
      ans += zeros;
    }
    else if(!sd && !td) {
      ans += ones;
    }

    if(sd && !td) {
      ++oz;
    }
    if(!sd && !td) {
      ++zz;
    }
    if(!sd) {
      ++zeros;
    }
    if(sd) {
      ++ones;
    }

  }
  cout << ans;
  return 0;
}
