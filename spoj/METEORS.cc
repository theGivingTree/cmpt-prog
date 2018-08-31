#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
using LL = long long;

int n, m, K;
vector<int> owns[300000];
int goal[300000];
int metL[300000], metR[300000], metC[300000];
int lo[300000], hi[300000];
vector<int> qa[300000];
LL tr[300001];
void ft_update(int x, int val) {
  for(; x<=m; x+=x&-x) tr[x] += val;
}
LL ft_query(int x) {
  LL sum=0;
  for(; x>0; x-=x&-x) sum += tr[x];
  return sum;
}
void kaboom(int q) {
  int L = metL[q], R = metR[q], C = metC[q];
  if(L>R) {
    ft_update(L, C);
    ft_update(1, C);
    ft_update(R+1, -C);
  }
  else {
    ft_update(L, C);
    ft_update(R+1, -C);
  }
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=1; i<=m; ++i) {
    int o;
    scanf("%d", &o);
    owns[o-1].push_back(i);
  }
  for(i=0; i<n; ++i) {
    int p;
    scanf("%d", &p); 
    goal[i] = p;
  }
  scanf("%d", &K);
  for(i=0; i<K; ++i) {
    scanf("%d%d%d", &metL[i], &metR[i], &metC[i]);
  }
  for(i=0; i<n; ++i) {
    lo[i] = 0, hi[i] = K;
  }
  while(true) {
    bool flag = true;
    for(i=0; i<n; ++i) {
      if(lo[i] == hi[i]) continue;
      qa[lo[i]+hi[i]>>1].push_back(i);
      flag = false;
    }
    if(flag) break;
    memset(tr+1, 0, m*sizeof(LL));

    for(i=0; i<K; ++i) {
      kaboom(i);
      for(int o: qa[i]) {
        LL sum=0;
        for(int sec: owns[o]) {
          sum += ft_query(sec);
          if(sum >= goal[o]) break;
        }
        if(sum < goal[o]) lo[o] = i+1;
        else hi[o] = i;
      }
      vector<int> empty;
      swap(empty, qa[i]);
    }
  }
  for(i=0; i<n; ++i) {
    if(hi[i] == K) puts("NIE");
    else printf("%d\n", hi[i]+1);
  }
}
