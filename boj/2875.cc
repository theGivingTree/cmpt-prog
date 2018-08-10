#include <cstdio>
using namespace std;
int N, M, K;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  K-=N%2;N/=2;
  if(N<M) K-=M-N;
  else if(N>M) K-=2*N-2*M;
  if(K<0) K=0;
  printf("%d", (N<M?N:M)-(K+2)/3);
  return 0;
}
