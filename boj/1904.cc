#include <cstdio>
using namespace std;
int N, a=1, b=1, c=1;
int main() {
  scanf("%d", &N);
  for(int i=1; i<N; ++i) {
    c=(a+b)%15746;a=b;b=c;
  }
  printf("%d", c);
  return 0;
}
