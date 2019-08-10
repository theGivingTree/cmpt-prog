#include <cstdio>
using namespace std;
int N, Q;
int tra[2][100001];
void update(int tr[], int a) {
  for(int i=a; i<=N; i+=i&-i) ++tr[i];
}
int query(int tr[], int a) {
  int sum = 0;
  for(int i=a; i>0; i-=i&-i) sum += tr[i];
  return sum;
}
int query(int tr[], int a, int b) {
  return query(tr, b) - query(tr, a-1);
}
int main() {
  int i;
  scanf("%d%d", &N,&Q);
  for(i=1; i<=N; ++i) {
    int k;
    scanf("%d", &k);
    if(k<3) update(tra[--k], i);
  }
  for(i=0; i<Q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    int x0, x1;
    x0 = query(tra[0], a, b);
    x1 = query(tra[1], a, b);
    printf("%d %d %d\n", x0, x1, (b-a+1)-x0-x1);
  }
  return 0;
}
