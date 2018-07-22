#include <cstdio>
using namespace std;
using LL = long long;
int N, M, K;
LL a[1000000];
LL tree[4000001], lazy[4000001];
void build(int n, int s, int e) {
  if(e-s==1) {tree[n] = a[s]; return;}
  build(n*2, s, (s+e)/2);
  build(n*2+1, (s+e)/2, e);
  tree[n]= tree[n*2] + tree[n*2+1];
}
void update(int n, int s, int e, int a, int b, LL v) {
  if(b <= s || e <= a) return;

  tree[n] += lazy[n] * (e-s);
  if(e-s!=1) lazy[n*2] += lazy[n], lazy[n*2+1] += lazy[n];
  lazy[n] = 0;

  if(a <= s && e <= b) {
    tree[n] += (e-s)*v;
    if(e-s!=1) {
      lazy[n*2] += v;
      lazy[n*2+1] += v;
    }
    return;
  }

  update(n*2, s, (s+e)/2, a, b, v);
  update(n*2+1, (s+e)/2, e, a, b, v);
  tree[n] = tree[n*2] + tree[n*2+1];
}
LL query(int n, int s, int e, int a, int b) {
  tree[n] += lazy[n]*(e-s);
  if(e-s!=1) lazy[n*2] += lazy[n], lazy[n*2+1] += lazy[n];
  lazy[n] = 0;

  if(b <= s || e <= a) return 0;
  if(a <= s && e <= b) {
    return tree[n];
  }
  return query(n*2, s, (s+e)/2, a, b) + query(n*2+1, (s+e)/2, e, a, b);
}
int main() {
  int i, j;
  scanf("%d %d %d", &N, &M, &K);
  for(i=0; i<N; ++i) {
    scanf("%lld", a+i);
  }
  build(1, 0, N);
  for(i=0; i<M+K; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a==1) {
      LL d;
      scanf("%lld", &d);
      update(1, 0, N, b-1, c, d);
    }
    else {
      printf("%lld\n", query(1, 0, N, b-1, c));
    }
  }
  return 0;
}
