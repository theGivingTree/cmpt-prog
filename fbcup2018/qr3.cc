/* Ethan Searches for a String */
#include <iostream>
#include <cstring>
using namespace std;
int T, test_case;
char pat[2001];
int patsz;
char ans[4001];
int mp[2001];
void preMp(char *x, int m, int *mpNext) {
  int i, j;
  i=0, j=mpNext[0]=-1;
  while(i<m) {
    while(j>-1 and x[i]!=x[j]) j=mpNext[j];
    ++i, ++j;
    if(x[i]==x[j]) mpNext[i]=mpNext[j];
    else mpNext[i]=j;
  }
}
int main() {
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    int i;
    cin >> pat;
    patsz = strlen(pat);
    preMp(pat, patsz, mp);
    for(i=0; i<patsz and mp[i]<=0; ++i);
    cout << "Case #" << test_case << ": ";
    if(i==patsz) cout << "Impossible\n";
    else {
      strncpy(ans, pat, i);
      strncpy(ans+i, pat+mp[i], patsz-mp[i]+1);
      cout << ans << '\n';
    }
  }
  return 0;
}
