#include <cstdio>
constexpr int N_MAX = 250000;
using namespace std;
int arr[N_MAX];
int tree[(1<<16)+1];
void update(int i, int v) {
  for(; i<=65536; i+=i&-i) tree[i] += v;
}
int query(int i) {
  int sum = 0;
  for(; i>0; i-=i&-i) sum += tree[i];
  return sum;
}
int find(int x) {
  int sum = 0;
  int pos = 0;
  for(int i=16; i>=0; --i) {
    if(pos + (1<<i) <= 65536 && sum + tree[pos + (1<<i)] < x) {
      pos += 1<<i;
      sum += tree[pos];
    }
  }
  return pos + 1;
}
int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  for(int i=0; i<K-1; ++i) {
    int v;
    scanf("%d", &v);
    arr[i] = v;
    update(v+1, 1);
  }
  long long sum = 0;
  for(int i=K-1; i<N; ++i) {
    int v;
    scanf("%d", &v);
    arr[i] = v;
    update(v+1, 1);
    sum += find((K+1)/2) - 1;
    update(arr[i-K+1]+1, -1);
  }
  printf("%lld", sum);
  return 0;
}
