#include <cstdio>
using namespace std;
long long n, k;
int main() {
  scanf("%lld%lld",&n,&k);
  long long i = k-1;
  if(i>n) i=n;
  if(!(0<k-i && k-i<i)) {
    puts("0");
    return 0;
  }
  printf("%lld", (2*i-k+1)/2);
}
