#include <iostream>
#include <cstring>
using namespace std;
int T, test_case, l, i, j;
char a[21];
int main() {
  cin >> T;
  for(test_case=1; test_case<=T; ++test_case) {
    cin >> a;
    i=0,j=strlen(a)-1;
    for(;i<j && a[i]!='*' && a[j]!='*' && a[i]==a[j];++i,--j);
    cout << '#' << test_case << ' ' << ((i<j && a[i]!='*' && a[j]!='*')?"Not exist":"Exist") << endl;
  }
  return 0;
}
