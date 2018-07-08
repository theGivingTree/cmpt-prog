#include <iostream>
using namespace std;
using LL = long long;
int T;
LL a[101]={0,1,1,1,2,2};
int b;
int main() {
  for(int i=6; i<=100; ++i) a[i]=a[i-1]+a[i-5];
  cin >> T;
  while(T--) {
    cin >> b;
    cout << a[b] << '\n';
  }
  return 0;
}
