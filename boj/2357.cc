#include <cstdio>
using namespace std;
int N, M, a[100000];
int tree1[100000*4+1];
int tree2[100000*4+1];
void build(int n, int s, int e) {
  if(e-s == 1) {
    tree1[n] = tree2[n] = a[s];
    return;
  }
  build(n*2, s, (s+e)/2);
  build(n*2+1, (s+e)/2, e);
  int L, R;
  L = tree1[n*2], R = tree1[n*2+1];
  tree1[n] = L < R ? L : R;
  L = tree2[n*2], R = tree2[n*2+1];
  tree2[n] = L > R ? L : R;
}
int query1(int n, int s, int e, int a, int b) {
  if(b <= s || e <= a) return 0x7fffffff;
  if(a<=s && e<=b) return tree1[n];
  int L, R;
  L = query1(n*2, s, (s+e)/2, a, b);
  R = query1(n*2+1, (s+e)/2, e, a, b);
  return L < R ? L : R;
}
int query2(int n, int s, int e, int a, int b) {
  if(b <= s || e <= a) return 0x80000000;
  if(a<=s && e<=b) return tree2[n];
  int L, R;
  L = query2(n*2, s, (s+e)/2, a, b);
  R = query2(n*2+1, (s+e)/2, e, a, b);
  return L > R ? L : R;
}
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for(i=0; i<N; ++i) {
    scanf("%d", a+i);
  }
  build(1, 0, N);
  for(i=0; i<M; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d %d\n", query1(1, 0, N, x-1, y), query2(1, 0, N, x-1, y));
  }
  return 0;
}
