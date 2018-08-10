#include <cstdio>
#include <algorithm>
using namespace std;
int divceil(int a, int b) {
  return (a+b-1)/b;
}
int main() {
  int i, j, n;
  scanf("%d", &n);
  for(i=1; i*i<=n; ++i);
  --i;
  int lds = i;
  for(i=0; i<n/lds; ++i) {
    for(j=0; j<lds; ++j) {
      printf("%d ", i*lds + lds-j);
    }
  }
  for(i=0; i<n%lds; ++i) {
    printf("%d ", (n/lds)*lds + (n%lds)-i);
  }
  return 0;
}
